import doctest, math

def distance(p1, p2):
    '''
    >>> distance((0, 0), (3,4))
    25
    >>> distance((0,0), (1,1))
    2
    '''
    return (pow(p1[0]-p2[0],2) + pow(p1[1]-p2[1],2))

if __name__ == "__main__":
    doctest.testmod()
