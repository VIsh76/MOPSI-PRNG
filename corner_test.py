#Corner test
#On fera genx,geny deux listes de nombres random ; le parametre du test est a = nb realisations = taille fenetre

import csv
import matplotlib.pyplot as plt
a=1000000000
crx=csv.reader(open("Varx.csv","rb"))
cry=csv.reader(open("Vary.csv","rb"))
def corner_test(a) : 
#    genx=[4,7,3,1,4,6,8,3]
#    geny=[3,8,4,1,9,5,9,4]
    genx=[]
    geny=[]
    for row in crx : 
        genx+=row
    for row in cry : 
        geny+=row
    plt.axis([0,a,0,a]) #zoom sur la fenetre
    plt.scatter(genx,geny,c='black')

corner_test(a)
