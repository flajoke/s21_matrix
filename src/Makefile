GET_LIBCHECK_CFLAGS=`pkg-config check --cflags --libs`
CFLAGS=--debug -Wall -Wextra -lm

LIBCHECK_SRC=./tests/*.c

TARGET=s21_matrix.a
DELETEME=./deleteme

SRC=\
	s21_calc_complements.c\
	s21_create_matrix.c\
	s21_remove_matrix.c\
	s21_determinant.c\
	s21_eq_matrix.c\
	s21_helpers.c\
	s21_mult_matrix.c\
	s21_mult_number.c\
	s21_invers_matrix.c\
	s21_sub_matrix.c\
	s21_sum_matrix.c\
	s21_transpose.c\

OBJ=$(addprefix $(DELETEME)/, $(SRC:%.c=%.o))

all: $(TARGET)


$(TARGET): $(DELETEME) $(OBJ)
	ar -rc $(TARGET) $(OBJ)
	ranlib $(TARGET)
	ar -t $(TARGET)


$(DELETEME): 
	-mkdir ./deleteme
	

./deleteme/%.o: %.c
	gcc -c $(CFLAGS) $< -o $@


clean:
	-rm -r $(DELETEME) 
	-rm $(TARGET)
	-rm *.gc*


test: $(TARGET)
	gcc $(LIBCHECK_SRC)        \
		$(CFLAGS)              \
		$(GET_LIBCHECK_CFLAGS) \
 		$(TARGET)              \
		-o $(DELETEME)/run
	$(DELETEME)/run


gcov_report: CFLAGS += --coverage -DS21_TEST
gcov_report: clean test
gcov_report:
#
	lcov                                       \
		--test-name 	"s21_matrix"           \
		--output-file 	$(DELETEME)/run.info   \
		--capture                              \
		--directory 	$(DELETEME)/           \
#
	genhtml                                    \
		--output-directory $(DELETEME)/report  \
		$(DELETEME)/run.info                   \
