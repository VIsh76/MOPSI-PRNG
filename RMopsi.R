zi <- read.csv("~/Documents/ENPC/MOPSI/MOPSI-PRNG/zigurat.csv", header=TRUE)
#help(ks.test)
plot.new()

x <-rnorm(1000,0,1)
hist(zi$value)
qqnorm(zi$value)
qqline(zi$value)