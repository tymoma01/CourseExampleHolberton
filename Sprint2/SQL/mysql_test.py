#!/usr/bin/python3
"""
List (id, name) from `states` filtered by an exact name, safely (no SQL injection).

Usage:
    ./safe_select_states.py <mysql_user> <mysql_password> <database> <state_name>

Example:
    ./safe_select_states.py root root hbtn_0e_0_usa "Arizona"
"""

import sys
import MySQLdb


def main():
    if len(sys.argv) != 5:
        print("Usage: {} <user> <password> <db> <state_name>".format(sys.argv[0]))
        sys.exit(1)

    user, password, db, state_name = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4]

    try:
        with MySQLdb.connect(host="localhost",
                             user=user,
                             passwd=password,
                             db=db,
                             charset="utf8mb4") as conn:
            with conn.cursor() as cur:
                cur.execute(
                    "SELECT id, name FROM states WHERE name=%s ORDER BY id ASC",
                    (state_name,)
                )
                rows = cur.fetchall()
                for row in rows:
                    print(row)

    except MySQLdb.OperationalError as e:
        sys.stderr.write(f"[OperationalError] {e}\n")
        sys.exit(2)
    except MySQLdb.Error as e:
        sys.stderr.write(f"[MySQLdb.Error] {e}\n")
        sys.exit(3)


if __name__ == "__main__":
    main()


# cat seed_states.sql | mysql -uroot -p
# ./mysql_test.py root root hbtn_0e_0_usa "Arizona"