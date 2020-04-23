#!/usr/bin/env python3
"""
generate_new_note [note_name] -n [categories] 

important things about nargs
https://docs.python.org/3.6/library/argparse.html#nargs
"""

import sys
import os
import time
import datetime
import argparse


# [ ] python dict missing var process
# [ ] add logger

# print(f'os.getcwd() : {os.path.abspath(os.getcwd())}')
# print(f'sys.argv[0] : {os.path.abspath(sys.argv[0])}')
# # real file path
# print(f'os.path.abspath(__file__) : {os.path.abspath(__file__)}')

__author__ = 'Hui Wang'
__version__ = 'v1.0'


def get_args():
    parser = argparse.ArgumentParser(description='A Script to generate a new solution')
    parser.add_argument('solution_name',
                        type=str,
                        nargs="?",
                        help='name for new solution',
                        )
    parser.add_argument('-n', '--number',
                        type=int,
                        help='solution number'
                        ) 
    args = parser.parse_args()
    
    return args

def main():
    args = get_args()
    root_dir = os.path.dirname(os.path.abspath(__file__))
    solution_name = f'{args.number:03d}_{args.solution_name}'
    solution_path = os.path.join(root_dir, solution_name)
    cxx_name = f'{os.path.join(solution_path, args.solution_name)}.cxx'
    py_name = f'{os.path.join(solution_path, args.solution_name)}.py'
    # generate files
    if not os.path.exists(solution_path):
        os.makedirs(solution_path)
        with open(cxx_name, mode='x',encoding='utf8') as f:
            pass
        with open(py_name, mode='x',encoding='utf8') as f:
            pass
        print(f'Create new solution at {solution_path}')
    else:
        print(f'the [{solution_path}] has already existed')
        raise FileExistsError



if __name__ == "__main__":
    main()
