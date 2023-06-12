#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int StrLength(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        ;
    return i;
}
void Upper(char *str) // converts lowercase char in str to uppercase
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    }
}
void Lower(char *str) // converts uppercase char in str to lowercase
{
    int i;
    for (i = 0; str[i] != '\0'; i++)

    {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
    }
}
void ToggleCase(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 65 && str[i] < 91)
            str[i] += 32;
        else if (str[i] >= 97 && str[i] < 123)
            str[i] -= 32;
    }
}
void VowelConsonants(char str[])
{
    int i;
    int vc = 0, cc = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            vc++;
        else if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
            cc++;
    }
    printf("%d is vowel count and\n%d is consonant count\n", vc, cc);
}
int WordCount(char str[]) // trailing spaces and whitespaces are not counted
{
    int i;
    int wc = 0;
    for (i = 1; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' && str[i - 1] != ' ')
            wc++;
    }
    return ++wc;
}
int IsValid(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (!(str[i] >= 65 && str[i] <= 90) && !(str[i] >= 97 && str[i] <= 122) && !(str[i] >= 48 && str[i] <= 57)) // check for invalid character
            return 0;
    }
    return 1;
}
char *ReverseAuxi(char *str) // reverse str using auxillary char array in heap
{
    int i, j;
    int l = StrLength(str) + 1;
    char *rstr;
    rstr = (char *)malloc(l * sizeof(char));
    for (i = 0; str[i] != '\0'; i++)
        ;
    i--;
    for (j = 0; i >= 0; j++, i--)
        rstr[j] = str[i];
    rstr[j] = '\0';

    return rstr;
}
void Reverse(char *str) // reverse a str using same char arr
{
    int i, j;
    char temp;
    for (j = 0; str[j] != '\0'; j++)
        ;
    j--;
    for (i = 0; i < j; j--, i++)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
int Compare(char *A, char *B) // both strings must be in same cases if not convert them to one of the case
{
    int i, j;
    for (i = 0, j = 0; A[i] != '\0' && B[j] != '\0'; i++, j++)
    {
        if (A[i] != B[j])
            break;
    }
    if (A[i] == B[j])
        // printf("Equal\n");
        return 0; // when both are equal
    else if (A[i] < B[j])
        // printf("Smaller\n");
        return -1; // first is smaller
    else
        // printf("Greater\n");
        return 1; // first is greater
}
void PalindromeAuxi(char *str) // using auxi char arr to store reverse of char arr and comparing both
{
    char *rstr;
    rstr = ReverseAuxi(str);
    if (!Compare(str, rstr))
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
}
void Palindrome(char *str) // checking in same array
{
    int i, j;
    char flag = 1;
    for (j = 0; str[j] != '\0'; j++)
    {
    }
    j--;
    for (i = 0; i < j; j--, i++)
    {
        if (str[i] != str[j])
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
}
void DuplicateCompare(char *str)
{
    // str contains only alphabets nor digits nor any special symbols
    int i, j, count;
    for (i = 0; str[i + 1] != '\0'; i++)
    {
        count = 1;
        for (j = i + 1; str[j] != '\0'; j++)
        {
            if (str[i] == str[j])
                count++;
        }
        if (count > 1)
            printf("%c appears %d\n", str[i], count);
    }
}
void DuplicateHashSameCase(char *str) // strig must be of samecase with only alphabets
{
    // str contains only alphabets nor digits nor any special symbols
    int i;
    char *H;
    Lower(str); // converting str to lowercase
    H = (char *)malloc(26 * sizeof(char));
    for (i = 0; i < 26; i++)
        H[i] = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        H[str[i] - 'a']++;
    }
    for (i = 0; i < 26; i++)
    {
        if (H[i] > 1)
            printf("%c appears %d\n", i + 'a', H[i]);
    }
}

void DuplicateHashCaseSensitive(char *str) // str is case sensitive and may contain both lower and upper alphabets
{                                          // str contains only alphabets nor digits nor any special symbols
    int i;
    char *Hl, *Hu;
    Hl = (char *)malloc(26 * sizeof(char));
    Hu = (char *)malloc(26 * sizeof(char));
    for (i = 0; i < 26; i++)
        Hl[i] = Hu[i] = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            Hl[str[i] - 'a']++;
        else
            Hu[str[i] - 'A']++;
    }
    for (i = 0; i < 26; i++)
    {
        if (Hu[i] > 1)
            printf("%c appears %d\n", i + 'A', Hu[i]);
        if (Hl[i] > 1)
            printf("%c appears %d\n", i + 'a', Hl[i]);
    }
}
void DuplicateBitSet(char *str) // str must be continous
{                               // str may or may not be in same case
    int i;
    long int H = 0, X = 0;           // H stores bit value at index numbered as numbers of aplhabets
    for (i = 0; str[i] != '\0'; i++) // scan through all the list
    {
        X = 1;
        X = X << (str[i] - 'a'); // shifts 1 to bit index which is a number of alphabet starting from 0
        if ((X & H) > 0)         // masking, checking if bit value at index is 1 or 0
            printf("%c is duplicate\n", str[i]);
        else
            H = X | H; // merging, setting 1 at bit index representation of current alphabet
    }
}
int Anagram(char *A, char *B)
{
    if (StrLength(A) != StrLength(B)) // checking if both strings are of equal length or not
        return 0;
    char H[26] = {0}; // init hash table with zeros
    int i;
    for (i = 0; A[i] != '\0'; i++)
        H[A[i] - 'a']++; // incrementing values of hash table for string A
    for (i = 0; B[i] != '\0'; i++)
    {
        H[B[i] - 'a']--;       // decrementing values for string B
        if (H[B[i] - 'a'] < 0) // checking if value at any index is negative
        {
            printf("Not Anagram!\n");
            return 0;
        }
    }
    printf("Anagram!\n");
    return 1;
}
void Swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void StringPermutation(char *str, int l, int h) // l and h are start and end index of given string
{                                               // This function uses recursion and swapping
    int i;
    if (h == l)
        printf("%s\n", str);
    else
    {
        for (i = l; i < h; i++) // iterate i through str
        {
            Swap(&str[l], &str[i]);           // swap char at l and i
            StringPermutation(str, l + 1, h); // call function with l incremented
            Swap(&str[l], &str[i]);           // again undo the changes made in string
        }
    }
}
void StringPermutationBackTracking(char *str, int k) // Backtracking is achieved by using Recursion to perform the bruteforce
{
    static int F[10] = {0};
    static char Res[10];
    int i;
    if (str[k] == '\0')
    {
        Res[k] = '\0';
        printf("%s\n", Res);
    }
    else
    {
        for (i = 0; str[i] != '\0'; i++)
        {
            if (F[i] == 0)
            {
                Res[k] = str[i];
                StringPermutationBackTracking(str, k + 1);
                F[i] = 0;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    char s[] = "ABC";
    char t[] = "tiawda";
    StringPermutationBackTracking(s, 0);
    return 0;
}
