"""
SQLAlchemy ORM example: define a State model, connect, create tables, and list states.

Usage:
    ./sqlalchemy_states_example.py <mysql_user> <mysql_password> <database>

Example:
    ./sqlalchemy_states_example.py root root hbtn_0e_6_usa
"""

import sys
from sqlalchemy import Column, Integer, String, create_engine
from sqlalchemy.orm import declarative_base, sessionmaker


# ORM base class
Base = declarative_base()


class State(Base):
    """SQLAlchemy ORM model mapped to the `states` table."""
    __tablename__ = "states"

    id = Column(Integer, 
                primary_key=True, 
                autoincrement=True, 
                nullable=False)
    name = Column(String(128), nullable=False)

    def __repr__(self):
        return f"<State id={self.id} name={self.name!r}>"

def build_url(user: str, password: str, db: str) -> str:
    # MySQL + mysqlclient (MySQLdb) dialect/driver
    # If your MySQL server is on a non-default port, append :3306 after localhost.
    return f"mysql+mysqldb://{user}:{password}@localhost/{db}"

def main():
    if len(sys.argv) != 4:
        print("Usage: {} <user> <password> <db>".format(sys.argv[0]))
        sys.exit(1)

    user, password, db = sys.argv[1], sys.argv[2], sys.argv[3]
    url = build_url(user, password, db)

    # Engine: pool_pre_ping=True avoids stale connection errors; future=True uses 2.0-style engine.
    engine = create_engine(url, pool_pre_ping=True, future=True)

    # Create tables if they don't exist (idempotent)
    Base.metadata.create_all(engine)

    # Session factory; expire_on_commit=False lets us access attributes post-commit without refresh.
    SessionLocal = sessionmaker(bind=engine, expire_on_commit=False, future=True)

    # Optional: insert sample data if table is empty, so the example prints something on a fresh DB.
    with SessionLocal() as session:
        if session.query(State).count() == 0:
            session.add_all([
                State(name="California"),
                State(name="Arizona"),
                State(name="Texas"),
                State(name="New York"),
                State(name="Nevada"),
            ])
            session.commit()

    # Query and print all states ordered by id
    with SessionLocal() as session:
        states = session.query(State).order_by(State.id).all()
        for st in states:
            # Match the project’s print style: "<id>: <name>"
            print(f"{st.id}: {st.name}")

if __name__ == "__main__":
    main()
