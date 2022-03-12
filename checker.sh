#------------------------------------------------------------------------------
# 
#   CHECKER PA 2022, Tema 0: Parc Auto
#   
#   Author: Udroiu Ruben
#
#------------------------------------------------------------------------------
#definire constante
# Exec name
EXEC_NAME=parcAuto

# Teste Normale
FILE_TEST_DATE_1="Input/t%d/date.in"
FILE_TEST_CERINTE="Input/t%d/cerinte.in"
FILE_TEST_DATE_2="Input/t%d/marci.in"
FILE_TEST_REF="Expected/expected%d.out"
FILE_TEST_OUT="Output/rezultate%d.out"
NUM_TESTS=3

# Format: "x=a,y=b,z=c..."
# x, y, z are test indexes
# Each test with an index less or equal to x gets a points.
# Each test with an index less or equal to y gets b points.
POINTS_TEST="1=20,2=30,3=50"

# Total score
SCORE_TESTS=0

# Delimitor
DELIM="-------------------------------------------------------------"
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'


points=0

function run_test {
  points=0
  msg=""
  color=$RED

  # Convert from Points string to array
  p_text=`echo $7 | tr ',' ' '`
  p_arr=($p_text)

  for x in "${p_arr[@]}";
  do
          tidx=`echo $x | cut -d'=' -f1`
          tpts=`echo $x | cut -d'=' -f2`
  
          if (( $1 <= $tidx ));
          then
      points=$tpts
                  break
          fi
  done

  # Okay, so this test will get $points if passed.
  ./$EXEC_NAME $2 $3 $5 $4 $6 2>&1 | cat
  
  diff -Z -q $5 $6 > /dev/null 2>&1
  if [ $? -eq 0 ];
  then
    msg="PASSED"
    color=$GREEN
  else
    msg="FAILED"
    color=$RED
    points=0
  fi

  printf "Test %2d ................................. ${color}%6s${NC} (+%2dpt)\n" $i $msg $points
}

function run_tests {
  for i in `seq 1 1 $1`
  do
    printf -v file_cerinte $2 $i
    printf -v file_date_1 $3 $i
    printf -v file_date_2 $4 $i
    printf -v file_out $5 $i
    printf -v file_ref $6 $i
    run_test $i $file_cerinte $file_date_1 $file_date_2 $file_out $file_ref $7
    
    SCORE_TESTS=$(($SCORE_TESTS+$points))
  done
}

function run_normal_tests {
  echo $DELIM
  echo "[TESTE NORMALE]"
  run_tests $NUM_TESTS $FILE_TEST_CERINTE $FILE_TEST_DATE_1 $FILE_TEST_DATE_2 $FILE_TEST_OUT $FILE_TEST_REF "$POINTS_TEST"

  echo
  printf "TOTAL ........................................... %3spt\n" $SCORE_TESTS 
  echo
}

function show_total {
  echo $DELIM
  echo "[NOTA FINALA]"
  
  echo
  printf "NOTA FINALA ..................................... %3spt\n" $(($SCORE_TESTS))
  echo  
}
# Clean
make clean
# Prepare output directory
rm -rf Output/
mkdir Output

# Build
make

# Run normal tests
echo $DELIM
echo "Executabil = '$EXEC_NAME'"

run_normal_tests
show_total