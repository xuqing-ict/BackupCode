#!/usr/bin/env python
#-*- coding: utf-8 *-*

__author__ = "QingXu"

'''
import logging
logging.basicConfig(level=logging.DEBUG)

s = '0'
n = int(s)
logging.info('n = %d' %n)
logging.warning('warining: n = %d' %n)
logging.debug('debug : n = %d' %n)
print 10/n
'''
import sys
import logging

LEVELS = {'debug':logging.DEBUG,
        'info':logging.INFO,
        'error': logging.ERROR,
        'critical': logging.CRITICAL}

if len(sys.argv) > 1:
    level_name = sys.argv[1]
    level = LEVELS.get(level_name,logging.NOTSET)
    logging.basicConfig(level=level)

logging.debug("This is a debug information")
logging.info("This is a info information")
logging.warning("This is a warning information")
logging.error("This is a error information")
logging.critical("This is a critical information")

