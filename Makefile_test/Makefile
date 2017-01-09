OBJS = main.o tool1.o tool2.o
CC   = gcc
CFLAGS += -c -Wall -g

# $@ 指上一句里的目标
# $^ 指上一句里的依赖

mytool:$(OBJS)
    $(CC) -o $@ $^


# % 是通配符

%.o:%.c
    $(CC) -o $(CFLAGS) $@ $^


clean:
    $(RM) *.o mytool -r
