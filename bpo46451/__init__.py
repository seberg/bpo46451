from .test import method
from .cytest import cy_method

import sys

from . import mod

def trace(frame, event, arg):
    print(mod.mod_global)

    return trace

sys.settrace(trace)

method("huhu!")

cy_method("huhu2!")

