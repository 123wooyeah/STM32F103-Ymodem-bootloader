#ifndef __ATK__PARADJ
#define __ATK__PARADJ

#ifdef __cplusplus
extern "C" {
#endif

/*
    宏的胶水运算需要用两个宏嵌套
*/
#define __CONNET2(_a,_b)  _a##_b
#define CONNET2(_a,_b) __CONNET2(_a,_b)

#define __CONNET3(a,b,c)  a##b##c
#define CONNET3(a,b,c) __CONNET3(a,b,c)

#define __CONNET4(a,b,c,d)  a##b##c##d
#define CONNET4(a,b,c,d) __CONNET4(a,b,c,d)

#define __CONNET5(a,b,c,d,e)  a##b##c##d##e
#define CONNET5(a,b,c,d,e) __CONNET5(a,b,c,d,e)

#define __CONNET6(a,b,c,d,e,f)  a##b##c##d##e##f
#define CONNET6(a,b,c,d,e,f) __CONNET6(a,b,c,d,e,f)

#define __CONNET7(a,b,c,d,e,f,g)  a##b##c##d##e##f##g
#define CONNET7(a,b,c,d,e,f,g) __CONNET7(a,b,c,d,e,f,g)

#define __CONNET8(a,b,c,d,e,f,g,h)  a##b##c##d##e##f##g##h
#define CONNET8(a,b,c,d,e,f,g,h) __CONNET8(a,b,c,d,e,f,g,h)


#define __CONNET9(a,b,c,d,e,f,g,h,i)  a##b##c##d##e##f##g##h##i
#define CONNET9(a,b,c,d,e,f,g,h,i) __CONNET9(a,b,c,d,e,f,g,h,i)


/*****************************************************/
#define ADDR_CHAR ".ARM.__AT_0x"
//#define __MY__AT_ADDR(ATOM_ADDR_VAL)   CONNET9(ADDR_CHAR,DATA_H7,DATA_H6,DATA_H5,DATA_H4,DATA_H3,DATA_H2,DATA_H1,DATA_H0)

#define GET_MATH_PART_VALUE(ATOM_ADDR_VAL)  CONNET9(ADDR_CHAR,DATA_H7,DATA_H6,DATA_H5,DATA_H4,DATA_H3,DATA_H2,DATA_H1,DATA_H0)
#define __MY__AT_ADDR(x)   GET_MATH_PART_VALUE(x)

/* 第7位数 */
#if ((((ATOM_ADDR_VAL)>>7*4)%0x10)==0x0)
    #define DATA_H7 "0"
#elif ((((ATOM_ADDR_VAL)>>7*4)%0x10)==0x1)
    #define DATA_H7 "1"
#elif ((((ATOM_ADDR_VAL)>>7*4)%0x10)==0x2)
    #define DATA_H7 "2"
#elif ((((ATOM_ADDR_VAL)>>7*4)%0x10)==0x3)
    #define DATA_H7 "3"
#elif ((((ATOM_ADDR_VAL)>>7*4)%0x10)==0x4)
    #define DATA_H7 "4"
#elif ((((ATOM_ADDR_VAL)>>7*4)%0x10)==0x5)
    #define DATA_H7 "5"
#elif ((((ATOM_ADDR_VAL)>>7*4)%0x10)==0x6)
    #define DATA_H7 "6"
#elif ((((ATOM_ADDR_VAL)>>7*4)%0x10)==0x7)
    #define DATA_H7 "7"
#elif ((((ATOM_ADDR_VAL)>>7*4)%0x10)==0x8)
    #define DATA_H7 "8"
#elif ((((ATOM_ADDR_VAL)>>7*4)%0x10)==0x9)
    #define DATA_H7 "9"
#elif ((((ATOM_ADDR_VAL)>>7*4)%0x10)==0xa)
    #define DATA_H7 "A"
#elif ((((ATOM_ADDR_VAL)>>7*4)%0x10)==0xb)
    #define DATA_H7 "B"
#elif ((((ATOM_ADDR_VAL)>>7*4)%0x10)==0xc)
    #define DATA_H7 "C"
#elif ((((ATOM_ADDR_VAL)>>7*4)%0x10)==0xd)
    #define DATA_H7 "D"
#elif ((((ATOM_ADDR_VAL)>>7*4)%0x10)==0xe)
    #define DATA_H7 "E"
#elif ((((ATOM_ADDR_VAL)>>7*4)%0x10)==0xf)
    #define DATA_H7 "F"
#else
    /* 错误处理 */
#endif

/* 第6位数 */
#if ((((ATOM_ADDR_VAL)>>6*4)%0x10)==0x0)
    #define DATA_H6 "0"
#elif ((((ATOM_ADDR_VAL)>>6*4)%0x10)==0x1)
    #define DATA_H6 "1"
#elif ((((ATOM_ADDR_VAL)>>6*4)%0x10)==0x2)
    #define DATA_H6 "2"
#elif ((((ATOM_ADDR_VAL)>>6*4)%0x10)==0x3)
    #define DATA_H6 "3"
#elif ((((ATOM_ADDR_VAL)>>6*4)%0x10)==0x4)
    #define DATA_H6 "4"
#elif ((((ATOM_ADDR_VAL)>>6*4)%0x10)==0x5)
    #define DATA_H6 "5"
#elif ((((ATOM_ADDR_VAL)>>6*4)%0x10)==0x6)
    #define DATA_H6 "6"
#elif ((((ATOM_ADDR_VAL)>>6*4)%0x10)==0x7)
    #define DATA_H6 "7"
#elif ((((ATOM_ADDR_VAL)>>6*4)%0x10)==0x8)
    #define DATA_H6 "8"
#elif ((((ATOM_ADDR_VAL)>>6*4)%0x10)==0x9)
    #define DATA_H6 "9"
#elif ((((ATOM_ADDR_VAL)>>6*4)%0x10)==0xa)
    #define DATA_H6 "A"
#elif ((((ATOM_ADDR_VAL)>>6*4)%0x10)==0xb)
    #define DATA_H6 "B"
#elif ((((ATOM_ADDR_VAL)>>6*4)%0x10)==0xc)
    #define DATA_H6 "C"
#elif ((((ATOM_ADDR_VAL)>>6*4)%0x10)==0xd)
    #define DATA_H6 "D"
#elif ((((ATOM_ADDR_VAL)>>6*4)%0x10)==0xe)
    #define DATA_H6 "E"
#elif ((((ATOM_ADDR_VAL)>>6*4)%0x10)==0xf)
    #define DATA_H6 "F"
#else
    /* 错误处理 */
#endif

/* 第5位数 */
#if ((((ATOM_ADDR_VAL)>>5*4)%0x10)==0x0)
    #define DATA_H5 "0"
#elif ((((ATOM_ADDR_VAL)>>5*4)%0x10)==0x1)
    #define DATA_H5 "1"
#elif ((((ATOM_ADDR_VAL)>>5*4)%0x10)==0x2)
    #define DATA_H5 "2"
#elif ((((ATOM_ADDR_VAL)>>5*4)%0x10)==0x3)
    #define DATA_H5 "3"
#elif ((((ATOM_ADDR_VAL)>>5*4)%0x10)==0x4)
    #define DATA_H5 "4"
#elif ((((ATOM_ADDR_VAL)>>5*4)%0x10)==0x5)
    #define DATA_H5 "5"
#elif ((((ATOM_ADDR_VAL)>>5*4)%0x10)==0x6)
    #define DATA_H5 "6"
#elif ((((ATOM_ADDR_VAL)>>5*4)%0x10)==0x7)
    #define DATA_H5 "7"
#elif ((((ATOM_ADDR_VAL)>>5*4)%0x10)==0x8)
    #define DATA_H5 "8"
#elif ((((ATOM_ADDR_VAL)>>5*4)%0x10)==0x9)
    #define DATA_H5 "9"
#elif ((((ATOM_ADDR_VAL)>>5*4)%0x10)==0xa)
    #define DATA_H5 "A"
#elif ((((ATOM_ADDR_VAL)>>5*4)%0x10)==0xb)
    #define DATA_H5 "B"
#elif ((((ATOM_ADDR_VAL)>>5*4)%0x10)==0xc)
    #define DATA_H5 "C"
#elif ((((ATOM_ADDR_VAL)>>5*4)%0x10)==0xd)
    #define DATA_H5 "D"
#elif ((((ATOM_ADDR_VAL)>>5*4)%0x10)==0xe)
    #define DATA_H5 "E"
#elif ((((ATOM_ADDR_VAL)>>5*4)%0x10)==0xf)
    #define DATA_H5 "F"
#else
    /* 错误处理 */
#endif

/* 第4位数 */
#if ((((ATOM_ADDR_VAL)>>4*4)%0x10)==0x0)
    #define DATA_H4 "0"
#elif ((((ATOM_ADDR_VAL)>>4*4)%0x10)==0x1)
    #define DATA_H4 "1"
#elif ((((ATOM_ADDR_VAL)>>4*4)%0x10)==0x2)
    #define DATA_H4 "2"
#elif ((((ATOM_ADDR_VAL)>>4*4)%0x10)==0x3)
    #define DATA_H4 "3"
#elif ((((ATOM_ADDR_VAL)>>4*4)%0x10)==0x4)
    #define DATA_H4 "4"
#elif ((((ATOM_ADDR_VAL)>>4*4)%0x10)==0x5)
    #define DATA_H4 "5"
#elif ((((ATOM_ADDR_VAL)>>4*4)%0x10)==0x6)
    #define DATA_H4 "6"
#elif ((((ATOM_ADDR_VAL)>>4*4)%0x10)==0x7)
    #define DATA_H4 "7"
#elif ((((ATOM_ADDR_VAL)>>4*4)%0x10)==0x8)
    #define DATA_H4 "8"
#elif ((((ATOM_ADDR_VAL)>>4*4)%0x10)==0x9)
    #define DATA_H4 "9"
#elif ((((ATOM_ADDR_VAL)>>4*4)%0x10)==0xa)
    #define DATA_H4 "A"
#elif ((((ATOM_ADDR_VAL)>>4*4)%0x10)==0xb)
    #define DATA_H4 "B"
#elif ((((ATOM_ADDR_VAL)>>4*4)%0x10)==0xc)
    #define DATA_H4 "C"
#elif ((((ATOM_ADDR_VAL)>>4*4)%0x10)==0xd)
    #define DATA_H4 "D"
#elif ((((ATOM_ADDR_VAL)>>4*4)%0x10)==0xe)
    #define DATA_H4 "E"
#elif ((((ATOM_ADDR_VAL)>>4*4)%0x10)==0xf)
    #define DATA_H4 "F"
#else
    /* 错误处理 */
#endif

/* 第3位数 */
#if ((((ATOM_ADDR_VAL)>>3*4)%0x10)==0x0)
    #define DATA_H3 "0"
#elif ((((ATOM_ADDR_VAL)>>3*4)%0x10)==0x1)
    #define DATA_H3 "1"
#elif ((((ATOM_ADDR_VAL)>>3*4)%0x10)==0x2)
    #define DATA_H3 "2"
#elif ((((ATOM_ADDR_VAL)>>3*4)%0x10)==0x3)
    #define DATA_H3 "3"
#elif ((((ATOM_ADDR_VAL)>>3*4)%0x10)==0x4)
    #define DATA_H3 "4"
#elif ((((ATOM_ADDR_VAL)>>3*4)%0x10)==0x5)
    #define DATA_H3 "5"
#elif ((((ATOM_ADDR_VAL)>>3*4)%0x10)==0x6)
    #define DATA_H3 "6"
#elif ((((ATOM_ADDR_VAL)>>3*4)%0x10)==0x7)
    #define DATA_H3 "7"
#elif ((((ATOM_ADDR_VAL)>>3*4)%0x10)==0x8)
    #define DATA_H3 "8"
#elif ((((ATOM_ADDR_VAL)>>3*4)%0x10)==0x9)
    #define DATA_H3 "9"
#elif ((((ATOM_ADDR_VAL)>>3*4)%0x10)==0xa)
    #define DATA_H3 "A"
#elif ((((ATOM_ADDR_VAL)>>3*4)%0x10)==0xb)
    #define DATA_H3 "B"
#elif ((((ATOM_ADDR_VAL)>>3*4)%0x10)==0xc)
    #define DATA_H3 "C"
#elif ((((ATOM_ADDR_VAL)>>3*4)%0x10)==0xd)
    #define DATA_H3 "D"
#elif ((((ATOM_ADDR_VAL)>>3*4)%0x10)==0xe)
    #define DATA_H3 "E"
#elif ((((ATOM_ADDR_VAL)>>3*4)%0x10)==0xf)
    #define DATA_H3 "F"
#else
    /* 错误处理 */
#endif

/* 第2位数 */
#if ((((ATOM_ADDR_VAL)>>2*4)%0x10)==0x0)
    #define DATA_H2 "0"
#elif ((((ATOM_ADDR_VAL)>>2*4)%0x10)==0x1)
    #define DATA_H2 "1"
#elif ((((ATOM_ADDR_VAL)>>2*4)%0x10)==0x2)
    #define DATA_H2 "2"
#elif ((((ATOM_ADDR_VAL)>>2*4)%0x10)==0x3)
    #define DATA_H2 "3"
#elif ((((ATOM_ADDR_VAL)>>2*4)%0x10)==0x4)
    #define DATA_H2 "4"
#elif ((((ATOM_ADDR_VAL)>>2*4)%0x10)==0x5)
    #define DATA_H2 "5"
#elif ((((ATOM_ADDR_VAL)>>2*4)%0x10)==0x6)
    #define DATA_H2 "6"
#elif ((((ATOM_ADDR_VAL)>>2*4)%0x10)==0x7)
    #define DATA_H2 "7"
#elif ((((ATOM_ADDR_VAL)>>2*4)%0x10)==0x8)
    #define DATA_H2 "8"
#elif ((((ATOM_ADDR_VAL)>>2*4)%0x10)==0x9)
    #define DATA_H2 "9"
#elif ((((ATOM_ADDR_VAL)>>2*4)%0x10)==0xa)
    #define DATA_H2 "A"
#elif ((((ATOM_ADDR_VAL)>>2*4)%0x10)==0xb)
    #define DATA_H2 "B"
#elif ((((ATOM_ADDR_VAL)>>2*4)%0x10)==0xc)
    #define DATA_H2 "C"
#elif ((((ATOM_ADDR_VAL)>>2*4)%0x10)==0xd)
    #define DATA_H2 "D"
#elif ((((ATOM_ADDR_VAL)>>2*4)%0x10)==0xe)
    #define DATA_H2 "E"
#elif ((((ATOM_ADDR_VAL)>>2*4)%0x10)==0xf)
    #define DATA_H2 "F"
#else
    /* 错误处理 */
#endif

/* 第1位数 */
#if ((((ATOM_ADDR_VAL)>>1*4)%0x10)==0x0)
    #define DATA_H1 "0"
#elif ((((ATOM_ADDR_VAL)>>1*4)%0x10)==0x1)
    #define DATA_H1 "1"
#elif ((((ATOM_ADDR_VAL)>>1*4)%0x10)==0x2)
    #define DATA_H1 "2"
#elif ((((ATOM_ADDR_VAL)>>1*4)%0x10)==0x3)
    #define DATA_H1 "3"
#elif ((((ATOM_ADDR_VAL)>>1*4)%0x10)==0x4)
    #define DATA_H1 "4"
#elif ((((ATOM_ADDR_VAL)>>1*4)%0x10)==0x5)
    #define DATA_H1 "5"
#elif ((((ATOM_ADDR_VAL)>>1*4)%0x10)==0x6)
    #define DATA_H1 "6"
#elif ((((ATOM_ADDR_VAL)>>1*4)%0x10)==0x7)
    #define DATA_H1 "7"
#elif ((((ATOM_ADDR_VAL)>>1*4)%0x10)==0x8)
    #define DATA_H1 "8"
#elif ((((ATOM_ADDR_VAL)>>1*4)%0x10)==0x9)
    #define DATA_H1 "9"
#elif ((((ATOM_ADDR_VAL)>>1*4)%0x10)==0xa)
    #define DATA_H1 "A"
#elif ((((ATOM_ADDR_VAL)>>1*4)%0x10)==0xb)
    #define DATA_H1 "B"
#elif ((((ATOM_ADDR_VAL)>>1*4)%0x10)==0xc)
    #define DATA_H1 "C"
#elif ((((ATOM_ADDR_VAL)>>1*4)%0x10)==0xd)
    #define DATA_H1 "D"
#elif ((((ATOM_ADDR_VAL)>>1*4)%0x10)==0xe)
    #define DATA_H1 "E"
#elif ((((ATOM_ADDR_VAL)>>1*4)%0x10)==0xf)
    #define DATA_H1 "F"
#else
    /* 错误处理 */
#endif

/* 第0位数 */
#if ((((ATOM_ADDR_VAL)>>0*4)%0x10)==0x0)
    #define DATA_H0 "0"
#elif ((((ATOM_ADDR_VAL)>>0*4)%0x10)==0x1)
    #define DATA_H0 "1"
#elif ((((ATOM_ADDR_VAL)>>0*4)%0x10)==0x2)
    #define DATA_H0 "2"
#elif ((((ATOM_ADDR_VAL)>>0*4)%0x10)==0x3)
    #define DATA_H0 "3"
#elif ((((ATOM_ADDR_VAL)>>0*4)%0x10)==0x4)
    #define DATA_H0 "4"
#elif ((((ATOM_ADDR_VAL)>>0*4)%0x10)==0x5)
    #define DATA_H0 "5"
#elif ((((ATOM_ADDR_VAL)>>0*4)%0x10)==0x6)
    #define DATA_H0 "6"
#elif ((((ATOM_ADDR_VAL)>>0*4)%0x10)==0x7)
    #define DATA_H0 "7"
#elif ((((ATOM_ADDR_VAL)>>0*4)%0x10)==0x8)
    #define DATA_H0 "8"
#elif ((((ATOM_ADDR_VAL)>>0*4)%0x10)==0x9)
    #define DATA_H0 "9"
#elif ((((ATOM_ADDR_VAL)>>0*4)%0x10)==0xa)
    #define DATA_H0 "A"
#elif ((((ATOM_ADDR_VAL)>>0*4)%0x10)==0xb)
    #define DATA_H0 "B"
#elif ((((ATOM_ADDR_VAL)>>0*4)%0x10)==0xc)
    #define DATA_H0 "C"
#elif ((((ATOM_ADDR_VAL)>>0*4)%0x10)==0xd)
    #define DATA_H0 "D"
#elif ((((ATOM_ADDR_VAL)>>0*4)%0x10)==0xe)
    #define DATA_H0 "E"
#elif ((((ATOM_ADDR_VAL)>>0*4)%0x10)==0xf)
    #define DATA_H0 "F"
#else
    /* 错误处理 */
#endif

#define FOCK_ABC(x) __MY__AT_ADDR(x)
#define __ATTRIBUTE_AT_SECTION_CHAR(x) __attribute__((section(__MY__AT_ADDR(x)))) 

/*****************************************************/



/*
    我们需要一个宏来把我们的变量预处理
    但宏不能直接计算公式：我的用宏的解析特性来展开
    地址都形如0x08041000，0x20000000
    共8个需要计算的数据，每个位都是0x0~0xF,
    我们要算出每个位的数并从高位到低位合并0xH7_H6_H5_H4_H3_H2_H1_H0
*/

//#define VAL (0x08041000+0x4)


#ifdef __cplusplus
}   /* extern "C"  */
#endif



#endif



