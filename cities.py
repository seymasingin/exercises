from sys import maxsize as mx
from math import sqrt, atan2

direction_to_angle = {
    "E" : 0,
    "NE": 0.78,
    "N" : 1.57,
    "NW": 2.35,
    "W" : 3.14,
    "SW": 3.92,
    "S" : 4.72,
    "SE": 5.51,
    "RE": 6.28
}

def atanWrapper(x,y):
    return atan2(y,x)%6.28

def readCities(file):
    cities = {}
    fp=open(file, "r")
    for line in fp:
        line = line.split()
        cities[line[0]]= {'x':int(line[1]),'y':int(line[2])}
    fp.close()
    return cities

def distance(cities,c1,c2):
    if(c1 not in cities):
        return -1
    if(c2 not in cities):
        return -2
    ax=cities[c1]["x"]
    ay=cities[c1]["y"]
    bx=cities[c2]["x"]
    by=cities[c2]["y"]
    distance=sqrt((ax-bx)**2+(ay-by)**2)
    return distance

def getDirection(target,x,y):
    d = atanWrapper(target["x"]-x,target["y"]-y)
    closest=""
    min_dif=10
    for w in direction_to_angle:
        dif = abs(direction_to_angle[w]-d)
        if(dif<min_dif):
            min_dif=dif
            closest=w
    if closest == "RE":
        closest = "E"
    return closest

def closest(cities,x,y):
    min_d=mx
    cl_city = ''
    for city in cities:
        d=sqrt((cities[city]['x']-x)**2+(cities[city]['y']-y)**2)
        if(d<min_d):
            min_d=d
            cl_city=city
    direction = getDirection(cities[cl_city],x,y)
    return cl_city, direction

def getCoordinantsFromUser():
    line = input("Enter x and y:")
    line = line.split()
    while len(line) != 2:
        print("Error: Enter two numbers with a space between them")
        line = input("Enter x and y:")
        line = line.split()
    return int(line[0]), int(line[1])

def main():
    c = readCities("cityHelper/data/cities.txt")
    x,y = getCoordinantsFromUser()
    city,direction = closest(c,x,y)
    print(city,direction)

if __name__ == "__main__":
    main()

