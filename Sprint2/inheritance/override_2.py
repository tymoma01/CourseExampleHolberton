class SafeList(list):
    def __init__(self, *args, **kw):
        self._mutations = 0
        super().__init__(*args, **kw)

    def __setitem__(self, i, v):
        self._mutations += 1
        return super().__setitem__(i, v)

class BadList(SafeList):
    def __setitem__(self, i, v):
        list.__setitem__(self, i, v)
