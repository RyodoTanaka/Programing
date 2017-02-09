import collections
import copy
import warnings

import numpy
import six

from chainer import cuda
from chainer import initializers
from chainer import variable


def _is_shape(value):
    if value is None:
        return True
    elif isinstance(value, collections.Sequence):
        try:
            return all(int(x) for x in value)
        except TypeError:
            return False
    try:
        return int(value)
    except TypeError:
        return False

    return False


def _ensure_shape_dtype(value):
    # Return value paired with dtype FP32 if it is a shape.
