#include <stdio.h>
#include <stddef.h> // 为了使用 size_t

/**
 * 简单的 memcpy 实现
 * 
 * @param dest 目标内存地址
 * @param src  源内存地址
 * @param n    要复制的字节数
 * @return     返回目标指针 dest
 */
void *my_memcpy(void *dest, const void *src, size_t n) {
    // 将 void 指针转换为 char 指针，以便按字节操作
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    // 逐字节复制
    while (n--) {
        *d++ = *s++;
    }

    return dest;
}

// 测试代码
int main() {
    const char source[] = "Hello, World!";
    char destination[20];
    
    // 初始化 destination 以防万一
    for(int i=0; i<20; i++) destination[i] = 0;

    // 调用自定义 memcpy
    // 复制 sizeof(source) 包括结尾的 '\0'
    my_memcpy(destination, source, sizeof(source));

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}
