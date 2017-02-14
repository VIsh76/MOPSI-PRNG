#Corner test
#On fera genx,geny deux listes de nombres random ; le parametre du test est a = nb realisations = taille fenetre

import csv
import matplotlib.pyplot as plt
a=1
crx=csv.reader(open("Corner_Please/low_dis_1.csv","rb"))
cry=csv.reader(open("Corner_Please/low_dis_2.csv","rb"))
def corner_test(a) :
#    genx=[4,7,3,1,4,6,8,3]
#    geny=[3,8,4,1,9,5,9,4]
    genx=[]
    geny=[]
    for row in crx :
        genx+=row
    for row in cry :
        geny+=row
    #print genx[0]
    plt.axis([0,a,0,a]) #zoom sur la fenetre
    plt.scatter(genx,geny,c='black')
    plt.show()
corner_test(a)
