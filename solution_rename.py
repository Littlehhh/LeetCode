#!/usr/bin/env python3

import os
import sys
import re
import glob


if __name__ == "__main__":
    root_dir = os.path.dirname(os.path.abspath(__file__))
    pattern = '*[0-9]_*'
    dir_names = glob.glob(os.path.join(root_dir, pattern))
    base_names = [os.path.basename(base_name).split('_') for base_name in dir_names]
    for [number, name], origin_name in zip(base_names, dir_names):
        number=int(number)
        new_name = f'{number:04d}_{name}'
        os.rename(origin_name, os.path.join(root_dir, new_name))
    # os.rename()

    # print( base_names)

    # print(pattern)


    # solution_new_name = f'{number:03d}_{solution_name}'

