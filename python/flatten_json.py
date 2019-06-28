import json
import sys
from collections import OrderedDict


def flatten_json(x):
    d = OrderedDict()
    # keys = sorted(x.keys())
    keys = x.keys()
    # print(x, keys)
    for k in keys:
        if(isinstance(x[k], dict)):
          xx = flatten_json(x[k]) 
          for kk, vv in xx.items():
              d["%s.%s" % (k, kk)] = vv
        else:
            d[k] = x[k]
    
    return d



if __name__ == "__main__":
    input_str = sys.stdin.read()
    # print(json.loads(input_sr))
    od = json.JSONDecoder(object_pairs_hook=OrderedDict).decode(input_str)
    # od = json.loads(input_str)
    xx = flatten_json(od)
    print("{")
    l = len(xx.items())
    c = 0
    for k, v in xx.items():
        comma = c < l - 1
        print(('  \"%s\": %s' % (k, v)) + (',' if comma else ''))
        c += 1
    print('}')