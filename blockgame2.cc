#include <stdio.h>
#include <string.h>

char memo[1 << 25];
int moves[120], moves_cur;

int inline pos_to_bit(int r, int c) { return 1 << (5 * r + c); }

void init() {
    memset(memo, -1, sizeof(memo));
    memo[0] = 0;

    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            int cell_0_0 = pos_to_bit(r, c);
            int cell_0_1 = pos_to_bit(r, c + 1);
            int cell_1_0 = pos_to_bit(r + 1, c);
            int cell_1_1 = pos_to_bit(r + 1, c + 1);

            int sum = cell_0_0 + cell_0_1 + cell_1_0 + cell_1_1;

            moves[moves_cur++] = sum - cell_0_0;
            moves[moves_cur++] = sum - cell_0_1;
            moves[moves_cur++] = sum - cell_1_0;
            moves[moves_cur++] = sum - cell_1_1;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            moves[moves_cur++] = pos_to_bit(i, j) + pos_to_bit(i, j + 1);
            moves[moves_cur++] = pos_to_bit(j, i) + pos_to_bit(j + 1, i);
        }
    }
}

char get_memo(int state) {
    if (memo[state] != -1) return memo[state];

    char &ret = memo[state] = 0;
    for (int i = 0; i < moves_cur; i++) {
        if ((state & moves[i]) == 0) {
            if (!get_memo(state | moves[i])) {
                ret = 1;
                break;
            }
        }
    }

    return ret;
}

int main() {
    init();
    int C;
    scanf("%d", &C);
    while (C--) {
        int state = 0;

        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                char temp;
                scanf(" %c", &temp);
                if (temp == '#') state |= pos_to_bit(r, c);
            }
        }

        if (get_memo(state))
            printf("WINNING\n");
        else
            printf("LOSING\n");
    }

    return 0;
}