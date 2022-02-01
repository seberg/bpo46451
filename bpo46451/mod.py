mod_global = "this is a mod global"


def function(a, mod_global=None):
    if mod_global is not None:
        mod_global = a
    
    return

