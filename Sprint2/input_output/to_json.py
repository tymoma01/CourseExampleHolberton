def to_json(obj, attrs=None):
    d = obj.__dict__
    if isinstance(attrs, list) and all(isinstance(a, str) for a in attrs):
        return {k: d[k] for k in attrs if k in d}
    return d.copy()
