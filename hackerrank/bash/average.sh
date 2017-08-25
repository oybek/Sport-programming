
read N
s=0

for (( i=0; i<N; ++i ))
do
	read t
	s=$((s+t))
done

printf "%.3f" `echo "$s/$N" | bc -l`

