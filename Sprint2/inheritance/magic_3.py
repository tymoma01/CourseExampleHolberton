class Managed:
    def __enter__(self): 
        print("entering")
        return self
    
    def __exit__(self, exc_type, exc_val, exc_tb): 
        print("exiting")

with Managed():
    print("inside")
