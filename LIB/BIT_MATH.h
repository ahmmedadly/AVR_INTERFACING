#ifndef BIT_MATH_H_  //if we donot define this library before=file gard 
#define BIT_MATH_H_

#define SET_BIT(var,BIT) (var|=(1<<BIT))
#define CLR_BIT(var,BIT) (var&=(~(1<<BIT)))
#define CLR_PORT(var) (var=0x00)
#define set_port(var) (var=0xFF)
#define TOGGLE_BIT(var,BIT) (var^=(1<<BIT))
#define GET_BIT(VAR,BIT)  ((VAR>>BIT)&1)

#endif
