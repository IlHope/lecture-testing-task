#include <stdio.h>
#include <time.h>
#include "stack.h"

#define N 1000000

void benchmark_push() {
    Stack s;
    initStack(&s);

    clock_t start = clock();

    for (int i = 0; i < N; i++) {
        push(&s, i);
    }

    clock_t end = clock();

    double elapsed_ms = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

    printf("Push benchmark:\n");
    printf("  Total pushes: %d\n", N);
    printf("  Total time: %.3f ms\n", elapsed_ms);
    printf("  Avg per push: %.6f microseconds\n\n", (elapsed_ms * 1000.0) / N);

    destroyStack(&s);
}

// Функция для измерения pop()
void benchmark_pop() {
    Stack s;
    initStack(&s);

    // Заполняем стек заранее
    for (int i = 0; i < N; i++) {
        push(&s, i);
    }

    clock_t start = clock();

    for (int i = 0; i < N; i++) {
        pop(&s);
    }

    clock_t end = clock();

    double elapsed_ms = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

    printf("Pop benchmark:\n");
    printf("  Total pops: %d\n", N);
    printf("  Total time: %.3f ms\n", elapsed_ms);
    printf("  Avg per pop: %.6f microseconds\n\n", (elapsed_ms * 1000.0) / N);
}

int main() {
    printf("=== Stack benchmark ===\n\n");

    benchmark_push();
    benchmark_pop();

    return 0;
}