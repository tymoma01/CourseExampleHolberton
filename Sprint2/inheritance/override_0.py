class K:
    def f(self, value): 
        return f"method {value}"
k = K()
k.f = "oops"
print(k.f(1))