set title "Comparació de temps de quicksort"
set xlabel "n"
set ylabel "temps (s)"

set grid
set key left top

set logscale x
set logscale y

plot "temps_quicksort.dat" using 1:2:3 with yerrorlines title "quicksort while", \
     "temps_quicksort.dat" using 1:4:5 with yerrorlines title "quicksort pdf", \
     "temps_quicksort.dat" using 1:6:7 with yerrorlines title "quicksort while ahorro"