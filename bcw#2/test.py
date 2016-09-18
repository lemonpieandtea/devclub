#!/usr/bin/env python

import grading.tester as tester
from sys import argv, exit

if len(argv) != 4 or argv[3] not in ['console', 'file']:
    print('Usage: %s <executable> <test> <io method>' % argv[0])
    print('       <executable> - compiled program to launch during test')
    print('       <test>       - file with test data')
    print('       <io method>  - console / file')
    exit(0)

result = tester.run(argv[1], argv[2], argv[3] == 'file')

print "%d/%d passed" % (result['passed'], result['total'])

for diff in result['diff']:
    print ''
    print "==== Input ====="
    print diff['input']
    print "==== Result ===="
    print diff['result'],
    print "=== Expected ==="
    print diff['expected'],

