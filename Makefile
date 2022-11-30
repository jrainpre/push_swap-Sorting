SRCS	=	test.c lst_func.c swap.c take_args_str.c rules.c small_sort1.c sorting.c
RM        =    rm -f
CC        =    gcc
CFLAGS    =     -g #-Wall -Wextra -Werror -g
NAME    =    push_swap

all: $(NAME)

$(NAME):
	$(MAKE) all -C ./libft
	$(CC) -o $(NAME) $(CFLAGS) $(SRCS) ./libft/libft.a

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
    
re: fclean all

test: $(NAME)
	./push_swap "901 -638 309 594 -328 -305 -8 -992 -917 912 -532 -472 636 -650 408 92 214 927 666 -218 -200 -772 364 -221 -918 697 -126 611 -346 -662 -152 -604 -916 360 -782 95 -767 -976 949 750 -488 -606 456 484 224 -625 688 -405 -281 -226 639 871 -14 667 820 -788 -510 -826 846 500 -147 643 588 90 654 341 -216 934 -857 -277 278 565 -303 175 -641 678 -436 -926 -998 -359 141 935 605 377 -565 -741 273 -896 121 -43 54 -751 -571 -352 531 -867 -891 86 958 -402"

val: all
	valgrind --leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--verbose \
		--log-file=valgrind-out.txt \
		./push_swap 18 667 650 714 988 392 301 639 855 247 715 30 229 56 987 556 766 413 854 544 262 105 376 8 377 225 885 764 345 954 387 948 6 487 11 73 368 420 69 433 144 701 31 432 609 356 340 740 826 791 173 78 608 566 77 830 409 539 615 727 378 573 619 164 364 985 822 780 309 285 653 330 565 169 365 762 778 63 581 357 519 828 400 861 57 123 339 337 486 761 86 290 516 481 813 426 815 7 322 215 196 773 181 465 131 588 892 689 226 990 803 167 237 278 817 994 672 866 424 523 270 531 831 419 579 606 546 604 316 637 488 162 159 295 798 936 796 669 401 311 35 161 960 625 496 245 436 520 313 456 697 941 824 550 263 951 34 256 754 629 827 22 877 736 332 587 266 41 843 882 106 3 883 224 995 833 71 390 165 922 138 656 691 431 679 428 542 182 710 281 570 728 450 259 25 850 47 452 522 353 635 846 734 917 216 126 4 203 621 342 336 16 193 234 228 437 204 111 717 585 498 154 699 610 547 302 920 518 834 842 134 315 192 676 133 209 859 743 858 395 612 17 873 906 202 781 130 350 362 213 214 293 823 768 694 848 716 871 695 383 786 45 46 235 540 862 294 557 385 434 64 55 958 191 759 632 258 170 1 335 742 238 477 158 512 188 879 1000 722 787 466 640 725 142 283 2 777 119 511 327
		code valgrind-out.txt
    
.PHONY: all clean fclean re so_long test val