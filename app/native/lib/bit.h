#ifndef BIT_H_
#define BIT_H_

#define BIT(index) (1UL << index)
#define BIT_IS_SET(byte, index) (byte & BIT(index))

#endif // BIT_H_
