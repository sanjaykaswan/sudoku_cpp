/* we do not find sudoku instead we will reverse track the original sudoku using its compulsory conditions that 
1>  in an raw all elements must be diffrent and from 1 to 9 
2> in an column all elements must be different and from 1 to 9
3> divide sudoku in 9 squars of side 3 , in each square all elements must be 1 to 9 and must not repeate

we will pick element from 1 to 9 and check all conditions if these are true then we will put element on that position 
if none of the element satisfies all conditions than we go back and change elements ragarding conditions true*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // sudoku as rows in vector
    vector<vector<int>> v{{3, 5, 0, 6, 2, 7, 0, 0, 0}, {0, 6, 9, 8, 0, 3, 2, 0, 7}, {0, 0, 0, 5, 0, 4, 0, 1, 0}, {7, 3, 0, 9, 0, 0, 5, 6, 1}, {8, 0, 0, 0, 0, 0, 4, 0, 0}, {6, 0, 0, 0, 0, 1, 3, 0, 0}, {0, 2, 0, 3, 0, 9, 0, 4, 5}, {0, 0, 0, 0, 7, 5, 8, 0, 0}, {5, 7, 3, 2, 0, 0, 0, 0, 6}};
    // a copy of main sudoku so we can see which elements are initially given
    vector<vector<int>> vt{{3, 5, 0, 6, 2, 7, 0, 0, 0}, {0, 6, 9, 8, 0, 3, 2, 0, 7}, {0, 0, 0, 5, 0, 4, 0, 1, 0}, {7, 3, 0, 9, 0, 0, 5, 6, 1}, {8, 0, 0, 0, 0, 0, 4, 0, 0}, {6, 0, 0, 0, 0, 1, 3, 0, 0}, {0, 2, 0, 3, 0, 9, 0, 4, 5}, {0, 0, 0, 0, 7, 5, 8, 0, 0}, {5, 7, 3, 2, 0, 0, 0, 0, 6}};
    int r = 0, c = 0;
    while (true)
    {
        int raw = 0, clm = 1, box = 0, e = 1; // three conditions  of raw column and the box in which elements must not repete.
        if (vt[r][c] == 0)                    // if the element is not given or we can say given as 0
        {
            for (e; e < 10; e++) // choose element from 1 to 9
            {
                raw = 0, clm = 1, box = 0;
                if (count(v[r].begin(), v[r].end(), e) == 0) // checking condition of raw
                {
                    raw = 1;
                }
                if (raw == 1) // if raw's condition is true then checking for column
                {
                    for (int cc = 0; cc < 9; cc++)
                    {
                        if (v[cc][c] == e)
                        {
                            clm = 0;
                            break;
                        }
                    }
                }
                if (raw == 1 && clm == 1) // at the end checking for square box of 9 elements
                {
                    box = 1;
                    for (int j = (r / 3) * 3; j < ((r / 3) * 3) + 3; j++) // range for raws
                    {
                        for (int k = (c / 3) * 3; k < ((c / 3) * 3) + 3; k++) // range for columns
                        {
                            if (v[j][k] == e)
                            {
                                box = 0;
                                break;
                            }
                        }
                        if (box == 0)
                        {
                            break;
                        }
                    }
                }
                if (box == 1) // if all three are true then pick the element
                {
                    break;
                }
            }
        }
        if (box == 1 || vt[r][c] != 0) // if the element is already given then check next otherwise put the e on that position
        {

            if (box == 1)
            {
                v[r][c] = e; // put e  on position
            }

            if (r == 8 && c == 8) // if it was last element of sudoku
            {
                break;
            }
            else if (c != 8) // any other element
            {
                c += 1;
            }
            else if (c == 8 && r != 8) // last element of raw except last raw
            {
                r += 1;
                c = 0;
            }
        }
        else if (box == 0) // if none of element 1 to 9 satisfy all three conditions then go back and change elements
        {
            while (true)
            {
                if (c != 0)
                {
                    c -= 1;
                }
                else if (c == 0 && r != 0)
                {
                    c = 8;
                    r -= 1;
                }

                if (vt[r][c] == 0) // change only elements which are given as 0 initially
                {
                    if (v[r][c] != 9) // if it's 9 it cannot be change
                    {
                        for (e = v[r][c] + 1; e < 10; e++) // if it's not 9 increase it and check all 3 conditions
                        {
                            raw = 0, clm = 1, box = 0;
                            if (count(v[r].begin(), v[r].end(), e) == 0)
                            {
                                raw = 1;
                            }
                            if (raw == 1)
                            {
                                for (int cc = 0; cc < 9; cc++)
                                {
                                    if (v[cc][c] == e)
                                    {
                                        clm = 0;
                                        break;
                                    }
                                }
                            }
                            if (raw == 1 && clm == 1)
                            {
                                box = 1;
                                for (int j = (r / 3) * 3; j < ((r / 3) * 3) + 3; j++)
                                {
                                    for (int k = (c / 3) * 3; k < ((c / 3) * 3) + 3; k++)
                                    {
                                        if (v[j][k] == e)
                                        {
                                            box = 0;
                                            break;
                                        }
                                    }
                                    if (box == 0)
                                    {
                                        break;
                                    }
                                }
                            }
                            if (box == 1)
                            {
                                break;
                            }
                        }
                        if (box == 1) // if all conditions satisfy put it on position otherwise go back and change another elemnet
                        {
                            v[r][c] = e;
                            if (r == 8 && c == 8)
                            {
                                break;
                            }
                            else if (c != 8)
                            {
                                c += 1;
                            }
                            else if (c == 8 && r != 8)
                            {
                                r += 1;
                                c = 0;
                            }
                            break;
                        }
                        else
                        {
                            v[r][c] = 0;
                        }
                    }
                    else
                    {
                        v[r][c] = 0;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 9; i++) // output as a sudoku
    {
        for (int j = 0; j < 9; j++)
        {
            cout << v[i][j] << " ";
            if (j == 2 || j == 5)
            {
                cout << " ||  ";
            }
        }
        cout << endl;
        if (i == 2 || i == 5)
        {
            cout << "___________________________" << endl;
            cout<<endl;
        }
    }

    return 0;
}