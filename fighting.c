#include <stdio.h>
#include <windows.h>
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void ice_arrow_printer(int i, int j, int k, int l, int m)
{
    setColor(9);
    if ((i == 7 || i == 6 ) && (j <= 15 * m && j >= 15 * m - 14) )
    {
        printf("-");
    }
    else
    {
        printf(" ");
    }
    setColor(7);
    return;
}
void water_ball_printer(int i, int j, int k, int l, int m)
{
    setColor(11);
    if ((i == 7 || i == 6 || i == 5 || i == 9 || i == 8 ) && (j <= 15 * m-3 && j >= 15 * m - 11) || (i == 4 || i == 10 ) && (j <= 15 * m - 4 && j >= 15 * m - 10) || (i == 3 || i == 11 ) && (j <= 15 * m - 5 && j >= 15 * m - 9))
    {
        printf(":");
    }
    else
    {
        printf(" ");
    }
    setColor(7);
    return;
}
void stone_ball_printer(int i, int j, int k, int l, int m)
{
    setColor(8);
    if ((i == 7 || i == 6 || i == 5 || i == 9 || i == 8 ) && (j <= 15 * m-3 && j >= 15 * m - 11) || (i == 4 || i == 10 ) && (j <= 15 * m - 4 && j >= 15 * m - 10) || (i == 3 || i == 11 ) && (j <= 15 * m - 5 && j >= 15 * m - 9))
    {
        printf("o");
    }
    else
    {
        printf(" ");
    }
    setColor(7);
    return;
}
void fire_arrow_printer(int i, int j, int k, int l, int m)
{
    setColor(12);
    if ((i == 7 || i == 6 ) && (j <= 15 * m && j >= 15 * m - 14) )
    {
        printf("^");
    }
    else
    {
        printf(" ");
    }
    setColor(7);
    return;
}
void ball_thrower_printer(int i, int j, int k, int l, int m)
{
    setColor(5);
    if (((i == 11 || i == 4) && (j <= 15 * m && j >= 15 * m - 14)) || (k == 15 * m + 4 && j <= 15 * m) || ((l == 18 - 15 * m || k == 15 * m - 4 || l == 11 - 15 * m) && (j >= 15 * m - 14 && j <= 15 * m)))
    {
        printf("*");
    }
    else
    {
        printf(" ");
    }
    setColor(7);
    return;
}
void arrow_thrower_printer(int i, int j, int k, int l, int n)
{
    setColor(1);
    if ((i == 4 && (j <= 15 * n && j >= 15 * n - 14)) ||
        ((k == 15 * n + 4 || k == 15 * n - 2 || k == 15 * n + 12 || l == 12 - 15 * n || l == 18 - 15 * n || l == 26 - 15 * n) && (j >= 15 * n - 14 && j <= 15 * n)) || (i == 1 && (j == 15 * n - 8 || j == 15 * n - 6) || (i == 2 && j == 15 * n - 7) || (j == 15 * n && (i == 5 || i == 6 || i == 7 || i == 8)) || (j == 15 * n - 14 && (i == 5 || i == 6 || i == 7 || i == 8))))
    {
        printf("*");
    }
    else
    {
        printf(" ");
    }
    setColor(7);
}
void fighter(int* h_ball,int* h_arrow,int choose_role_1){
    int n, m, choose_power_1; // n, m are used to set the positions of ball thrower and arrow thrower
    // choose_role_1 will be used to choose whether the person is playing as a ball_thrower or a arrow_thrower
    if (choose_role_1 == 0)
    {
        printf("The first person is a ball thrower so next person is a arrow thrower by default\n");
        n = 5;
        m = 1;
    }
    if (choose_role_1 == 1)
    {
        printf("The first person is a arrow thrower so next person is a ball thrower by default\n");
        n = 1;
        m = 5;
    }
    // by using choose_role_1 we have created a setup placing ball_thrower and arrow_thrower at their respective position
    for (int i = 1; i <= 15; i = i + 1)
    {
        printf("\n    ");
        for (int j = 1; j <= 75; j = j + 1)
        {
            int k = i + j;
            int l = i - j;
            ball_thrower_printer(i, j, k, l, m); // ball_thrower print
            arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
        }
    }
    if(choose_role_1==0){
        printf("You are ball thrower which is present at left and right one is arrow thrower your opponent\n");
    }
    if(choose_role_1==1){
        printf("You are arrow thrower which is present at left and right one is ball thrower your opponent\n");
    }
    // 
    // setup is created and now we will discuss about power from player_1
    //
    if (choose_role_1 == 0)
    {
        printf("As a ball thrower you can throw water_ball ,stone_ball at the arrow thrower choose (0 , 1)\n");
    }
    if (choose_role_1 == 1)
    {
        printf("As a arrow thrower you can throw fire_arrow ,ice_arrow at the arrow thrower choose (0 , 1)\n");
    }
    scanf("%d", &choose_power_1);
    // after deciding power we will now throwing something at player_2
    if (choose_power_1 == 0 && choose_role_1 == 0) // you are ball thrower and you chose power as water_ball
    {
        for (int i = 1; i <= 15; i = i + 1)
        {
            printf("\n    ");
            for (int j = 1; j <= 75; j = j + 1)
            {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                water_ball_printer(i, j, k, l, m + 1);
            }
        }
    }
    if (choose_power_1 == 1 && choose_role_1 == 0) // you are ball thrower and you chose power as stone_ball
    {
        for (int i = 1; i <= 15; i = i + 1)
        {
            printf("\n    ");
            for (int j = 1; j <= 75; j = j + 1)
            {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                stone_ball_printer(i, j, k, l, m + 1);
            }
        }
    }
    if (choose_power_1 == 0 && choose_role_1 == 1) // you are arrow thrower and you chose power as fire_arrow
    {
        for (int i = 1; i <= 15; i = i + 1)
        {
            printf("\n    ");
            for (int j = 1; j <= 75; j = j + 1)
            {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                fire_arrow_printer(i, j, k, l, n + 1);
            }
        }
    }
    if (choose_power_1 == 1 && choose_role_1 == 1) // you are arrow thrower and you chose power as ice_arrow
    {
        for (int i = 1; i <= 15; i = i + 1)
        {
            printf("\n    ");
            for (int j = 1; j <= 75; j = j + 1)
            {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                ice_arrow_printer(i, j, k, l, n + 1);
            }
        }
    }
    // now we will discuss about power from player_2
    int choose_role_2 = 1 - choose_role_1;
    if (choose_role_2 == 0)
    {
        printf("You are playing as a ball_thrower if you want to throw water_ball ,stone_ball choose (0 , 1) ");
    }
    if (choose_role_2 == 1)
    {
        printf("You are playing as a arrow_thrower if you want to throw fire_arrow ,ice_arrow choose (0 , 1) ");
    }
    int choose_power_2;
    scanf("%d", &choose_power_2);
    // after deciding power we will now throwing something at player_1
    if (choose_power_2 == 0 && choose_role_2 == 0 && choose_power_1==0) // you are playing as a ball thrower and you chose power as water_ball and player_1 chose fire arrow
    {
        for (int i = 1; i <= 15; i = i + 1)
        {
            printf("\n    ");
            for (int j = 1; j <= 75; j = j + 1)
            {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                fire_arrow_printer(i, j, k, l, n + 1);
                water_ball_printer(i, j, k, l, m - 1);
            }
        }
    }
    if (choose_power_2 == 0 && choose_role_2 == 0 && choose_power_1==1) // you are playing as a ball thrower and you chose power as water_ball and player_1 chose ice arrow
    {
        for (int i = 1; i <= 15; i = i + 1)
        {
            printf("\n    ");
            for (int j = 1; j <= 75; j = j + 1)
            {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                ice_arrow_printer(i, j, k, l, n + 1);
                water_ball_printer(i, j, k, l, m - 1);
            }
        }
    }
    if (choose_power_2 == 1 && choose_role_2 == 0 && choose_power_1==0) // you are playing as ball thrower and you chose power as stone_ball and player_1 chose fire arrow
    {
        for (int i = 1; i <= 15; i = i + 1)
        {
            printf("\n    ");
            for (int j = 1; j <= 75; j = j + 1)
            {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                fire_arrow_printer(i, j, k, l, n + 1);
                stone_ball_printer(i, j, k, l, m - 1);
            }
        }
    }
    if (choose_power_2 == 1 && choose_role_2 == 0 && choose_power_1==1) // you are playing as ball thrower and you chose power as stone_ball and player_1 chose ice arrow
    {
        for (int i = 1; i <= 15; i = i + 1)
        {
            printf("\n    ");
            for (int j = 1; j <= 75; j = j + 1)
            {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                ice_arrow_printer(i, j, k, l, n + 1);
                stone_ball_printer(i, j, k, l, m - 1);
            }
        }
    }
    if (choose_power_2 == 0 && choose_role_2 == 1 && choose_power_1 == 0 ) // you are playing as arrow thrower and you chose power as fire_arrow and player_1 choose water ball 
    {
        for (int i = 1; i <= 15; i = i + 1)
        {
            printf("\n    ");
            for (int j = 1; j <= 75; j = j + 1)
            {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                water_ball_printer(i, j, k, l, m + 1);
                fire_arrow_printer(i, j, k, l, n - 1);
            }
        }
    }
    if (choose_power_2 == 0 && choose_role_2 == 1 && choose_power_1 == 1 ) // you are playing as arrow thrower and you chose power as fire_arrow and player_1 choose stone ball 
    {
        for (int i = 1; i <= 15; i = i + 1)
        {
            printf("\n    ");
            for (int j = 1; j <= 75; j = j + 1)
            {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                stone_ball_printer(i, j, k, l, m + 1);
                fire_arrow_printer(i, j, k, l, n - 1);
            }
        }
    }
    if (choose_power_2 == 1 && choose_role_2 == 1 && choose_power_1 == 0) // you are arrow thrower and you chose power as ice_arrow and player_1 choose water ball
    {
        for (int i = 1; i <= 15; i = i + 1)
        {
            printf("\n    ");
            for (int j = 1; j <= 75; j = j + 1)
            {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                water_ball_printer(i, j, k, l, m + 1);
                ice_arrow_printer(i, j, k, l, n - 1);
            }
        }
    }
    if (choose_power_2 == 1 && choose_role_2 == 1 && choose_power_1 == 1) // you are arrow thrower and you chose power as ice_arrow and player_1 choose stone ball
    {
        for (int i = 1; i <= 15; i = i + 1)
        {
            printf("\n    ");
            for (int j = 1; j <= 75; j = j + 1)
            {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                stone_ball_printer(i, j, k, l, m + 1);
                ice_arrow_printer(i, j, k, l, n - 1);
            }
        }
    }
    // at the mid point now we will decide which of the two power win 
    if(choose_role_1==0) // you are playing as a ball thrower
    {
        if(choose_power_1==0 && choose_power_2==0) // you have chose power water ball and your opponent has chose fire arrow
        {
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                fire_arrow_printer(i, j, k, l, m + 2);
                water_ball_printer(i, j, k, l, m + 2);
                }
            }
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                water_ball_printer(i, j, k, l, m + 3);
                }
            }
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                water_ball_printer(i, j, k, l, m + 4);
                }
            }
            printf("The health of arrow thrower is decreased by : 50\n");
            *h_arrow=*h_arrow -50;
            printf("Current health of ball thrower is %d\n",*h_ball);
            printf("Current health of arrow thrower is %d\n",*h_arrow);
        }
        if(choose_power_1==0 && choose_power_2==1) // you have chose power water ball and your opponent has chose ice arrow
        {
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                water_ball_printer(i, j, k, l, n - 2);
                ice_arrow_printer(i, j, k, l, n - 2);
                }
            }
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                ice_arrow_printer(i, j, k, l, n - 3);
                }
            }
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                ice_arrow_printer(i, j, k, l, n - 4);
                }
            }
            printf("The health of ball thrower is decreased by : 50\n");
            *h_ball=*h_ball-50;
            printf("Current health of ball thrower is %d\n",*h_ball);
            printf("Current health of arrow thrower is %d\n",*h_arrow);
        }
        if(choose_power_1==1 && choose_power_2==1) // you have chose power stone ball and your opponent has chose ice arrow
        {
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                ice_arrow_printer(i, j, k, l, m + 2);
                stone_ball_printer(i, j, k, l, m + 2);
                }
            }
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                stone_ball_printer(i, j, k, l, m + 3);
                }
            }
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                stone_ball_printer(i, j, k, l, m + 4);
                }
            }
            printf("The health of arrow thrower is decreased by : 50\n");
            *h_arrow=*h_arrow-50;
            printf("Current health of ball thrower is %d\n",*h_ball);
            printf("Current health of arrow thrower is %d\n",*h_arrow);
        }
        if(choose_power_1==1 && choose_power_2==0) // you have chose power stone ball and your opponent has chose fire arrow
        {
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                stone_ball_printer(i, j, k, l, n - 2);
                fire_arrow_printer(i, j, k, l, n - 2);
                }
            }
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                fire_arrow_printer(i, j, k, l, n - 3);
                }
            }
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                fire_arrow_printer(i, j, k, l, n - 4);
                }
            }
            printf("The health of ball thrower is decreased by : 50\n");
            *h_ball=*h_ball-50;
            printf("Current health of ball thrower is %d\n",*h_ball);
            printf("Current health of arrow thrower is %d\n",*h_arrow);
        }
    }
    if(choose_role_1==1) // you are playing as a arrow thrower
    {
        if(choose_power_1==0 && choose_power_2==0) // you have chose power fire arrow and your opponent has chose water ball
        {
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                fire_arrow_printer(i, j, k, l, m - 2);
                water_ball_printer(i, j, k, l, m - 2);
                }
            }
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                water_ball_printer(i, j, k, l, m - 3);
                }
            }
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                water_ball_printer(i, j, k, l, m - 4);
                }
            }
            printf("The health of arrow thrower is decreased by : 50\n");
            *h_arrow=*h_arrow -50;
            printf("Current health of ball thrower is %d\n",*h_ball);
            printf("Current health of arrow thrower is %d\n",*h_arrow);
        }
        if(choose_power_1==0 && choose_power_2==1) // you have chose power fire arrow and your opponent has chose stone ball
        {
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                stone_ball_printer(i, j, k, l, n + 2);
                fire_arrow_printer(i, j, k, l, n + 2);
                }
            }
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                fire_arrow_printer(i, j, k, l, n + 3);
                }
            }
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                fire_arrow_printer(i, j, k, l, n + 4);
                }
            }
            printf("The health of ball thrower is decreased by : 50\n");
            *h_ball=*h_ball-50;
            printf("Current health of ball thrower is %d\n",*h_ball);
            printf("Current health of arrow thrower is %d\n",*h_arrow);
        }
        if(choose_power_1==1 && choose_power_2==1) // you have chose power ice arrow and your opponent has chose stone ball
        {
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                ice_arrow_printer(i, j, k, l, m - 2);
                stone_ball_printer(i, j, k, l, m - 2);
                }
            }
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                stone_ball_printer(i, j, k, l, m - 3);
                }
            }
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                stone_ball_printer(i, j, k, l, m - 4);
                }
            }
            printf("The health of arrow thrower is decreased by : 50\n");
            *h_arrow=*h_arrow-50;
            printf("Current health of ball thrower is %d\n",*h_ball);
            printf("Current health of arrow thrower is %d\n",*h_arrow);
        }
        if(choose_power_1==1 && choose_power_2==0) // you have chose power ice arrow and your opponent has chose water ball
        {
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                water_ball_printer(i, j, k, l, n + 2);
                ice_arrow_printer(i, j, k, l, n + 2);
                }
            }
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                ice_arrow_printer(i, j, k, l, n + 3);
                }
            }
            for (int i = 1; i <= 15; i = i + 1){
                printf("\n    ");
                for (int j = 1; j <= 75; j = j + 1)
                {
                int k = i + j;
                int l = i - j;
                ball_thrower_printer(i, j, k, l, m); // ball_thrower print
                arrow_thrower_printer(i, j, k, l, n); // arrow_thrower print
                ice_arrow_printer(i, j, k, l, n + 4);
                }
            }
            printf("The health of ball thrower is decreased by : 50\n");
            *h_ball=*h_ball-50;
            printf("Current health of ball thrower is %d\n",*h_ball);
            printf("Current health of arrow thrower is %d\n",*h_arrow);
        }
    }
}
int main()
{
    printf("Welcome to the game this game is for two persons one person is a arrow thrower and one is a ball thrower\n");
    printf("Choose your role (0 for ball thrower and 1 for arrow thrower)\n");
    int choose_role_1;
    scanf("%d",&choose_role_1);
    int h_ball_thrower=200;
    int h_arrow_thrower=200;
    fighter(&h_ball_thrower,&h_arrow_thrower,choose_role_1);
    if(h_ball_thrower > 0 && h_arrow_thrower > 0)
    {
        for(int i=1;i*h_ball_thrower*h_arrow_thrower>0;i++)
        {
            if(choose_role_1==0){
            fighter(&h_ball_thrower,&h_arrow_thrower,i%2);
            }
            if(choose_role_1==1){
            fighter(&h_ball_thrower,&h_arrow_thrower,1-i%2);
            }
        }
    }
    if(h_ball_thrower==0){
        printf("\n\n\n\n                                                      Ball thrower lost the match");
    }
    if(h_arrow_thrower==0){
        printf("\n\n\n\n                                                      Arrow thrower lost the match");
    }
    return 0;
}