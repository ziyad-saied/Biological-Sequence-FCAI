#include <cstdio>
#include <typeinfo>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;
//Class to store the index and character for every element in the file of DNA sequence
class Suff
{
//to store the index
public:
    int index;
//to store the place of Char in memory
public:
    char *suffix;
};

const int Characters=10000;
//array of chars to store the sequences in memory
char ArrOfChar[ Characters ];



//read function to read the file and store sequence in array.
int read()
{
    //file-->Pointer to a FILE object that identifies an input file.
    FILE * file;
    //Open the file name ziyad contain the sequences
    file = fopen("SEQUENCE.txt","r");
    int pointer=0;
    int i=0;
    //fgetc-->Get Characters from file (The Character pointed by 'pointer' )
    for(i; i < Characters; i++,pointer++ )            //  i=0 pointer=0
    {
        pointer = fgetc( file );   //  when pointer=0 -->A  ||    pointer=1 -->C
        ArrOfChar[ i ] = pointer;  //  ArrOfChar[0]=A       ||    ArrOfChar[1]=C
                                    //  i=1                  ||    i=2
                                    //   pointer=1            ||    pointer=2
    }


    //close the file
    fclose (file);
}


/****************************************************************/
/*****************************************************************/
//to compare the alphabetical suffix
int compare(class Suff suf1, class Suff suf2)
{   //strcmp is a built_in function.
    // This function starts comparing the first character of each string. If they are equal to each other,
    // it continues with next two chars.

    /**
    <0	the first character that does not match has a lower value in suf1 than in suf2
    0	the contents of both strings are equal
    >0	the first character that does not match has a greater value in suf1 than in suf2
    */
    if(strcmp(suf1.suffix, suf2.suffix)<0){
            return 1;
    }
    else{
        return 0;
    }

}


//Suffix array function to sort the array
int *SuffixArray(char *Arr,int leng)
{
    //class to store every suffix with its index
    class Suff store[leng];
    //to store the index and character of the the full sequence
    for (int i=0; i<leng; i++)
    {
        /*
        index:0 | 1 | 2 | 3 | 4 | 5 | 6  ......
        char :A | C | T | A | C | T | G  ......
        */
        store[i].index=i;
        store[i].suffix=(Arr+i);
        //to print every index with its character
        //cout<<store[i].index<<store[i].suffix<<endl;
    }
    //Sort the suffixes in the range [first,last) into ascending order.
    sort( store,  store+leng, compare);
    ///open file to write inside
    FILE * text;
    text = fopen("NAIVE_SUFFIX.txt","w");
    // Store indexes of all sorted suffixes in the suffix array
    int *suffixArr=new int[leng];
    //print the sorted suffixes indexes and write them to the file
    for (int i = 0; i < leng; i++)
    {
        suffixArr[i] = store[i].index;
        //cout<<i<<" "<<suffixArr[i]<<endl;
        //print index and the sorted suffixes
        fprintf(text,"%d %d\n",i,suffixArr[i]);
    }
    fclose (text);
}




/**************************************************************************/
const int Char=259617;
//array of chars to store the sequences in memory
char ArrOfCha[ Char ];
//read function to read the file and store sequence in array.
int read2()
{
    //file-->Pointer to a FILE object that identifies an input file.
    FILE * a;
    //Open the file name ziyad contain the sequences
    a = fopen("SEQUENCE.txt","r");
    int pointe=0;
    int i=0;
    //fgetc-->Get Char from file (The Character pointed by 'pointer' )
    for(i; i < Char; i++,pointe++ )            //  i=0 pointer=0
    {
        pointe = fgetc( a );   //  when pointer=0 -->A  ||    pointer=1 -->C
        ArrOfCha[ i ] = pointe;  //  ArrOfChar[0]=A       ||    ArrOfChar[1]=C
                                    //  i=1                  ||    i=2
                                    //   pointer=1            ||    pointer=2
    }


    //close the file
    fclose (a);
}



/*********************************************************/
/**********************************************************/
int *SuffixArray2(char *Arr)
{
    //class to store every suffix with its index
    class Suff store[Char];
    //to store the index and character of the the full sequence
    for (int i=0; i<Char; i++)
    {
        /*
        index:0 | 1 | 2 | 3 | 4 | 5 | 6  ......
        char :A | C | T | A | C | T | G  ......
        */
        store[i].index=i;
        store[i].suffix=(Arr+i);
        //to print every index with its character
        //cout<<store[i].index<<store[i].suffix<<endl;
    }
    //Sort the suffixes in the range [first,last) into ascending order.
    sort( store,  store+Char, compare);
    ///open file to write inside
    FILE * text;
    text = fopen("ALLGENOME.txt","w");
    // Store indexes of all sorted suffixes in the suffix array
    int *suffixArr=new int[Char];
    //print the sorted suffixes indexes and write them to the file
    for (int i = 0; i < Char; i++)
    {
        suffixArr[i] = store[i].index;
        //cout<<i<<" "<<suffixArr[i]<<endl;
        //print index and the sorted suffixes
        fprintf(text,"%d %d\n",i,suffixArr[i]);
    }
    fclose (text);
}




/********************************************************************************/
//Suffix array function to sort the array
auto start = high_resolution_clock::now();
int *SuffixArray3(char *Arr,int leng)
{
    //class to store every suffix with its index
    class Suff store[leng];
    //to store the index and character of the the full sequence
    for (int i=0; i<leng; i++)
    {
        /*
        index:0 | 1 | 2 | 3 | 4 | 5 | 6  ......
        char :A | C | T | A | C | T | G  ......
        */
        store[i].index=i;
        store[i].suffix=(Arr+i);
        //to print every index with its character
        //cout<<store[i].index<<store[i].suffix<<endl;
    }
    //Sort the suffixes in the range [first,last) into ascending order.
    sort( store,  store+leng, compare);

    // Store indexes of all sorted suffixes in the suffix array
    int *suffixArr=new int[leng];
    //print the sorted suffixes indexes and write them to the file
    for (int i = 0; i < leng; i++)
    {
        suffixArr[i] = store[i].index;
        cout<<i<<" "<<suffixArr[i]<<endl;
        //print index and the sorted suffixes

    }
auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop - start);
cout<<"time = "<<duration.count()*0.0000001<<" second"<<endl;
cout<<endl;
}



/******************************************************************************/
//Double N Log Log n first way
/******************************************************************************/
int A = 0, Inv[Characters], nInv[Characters], counter;

struct Suffix{
	int idx; // Suffix starts at idx, i.e. it's str[ idx .. L-1 ]
	// Compares two suffixes based on their first 2 symbols,
	// assuming we know the result for A symbols.
	bool operator<(const Suffix& Suffe) const
	{
	    /**

	    index:     | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |12| 13| 14|
   ------------------------------------------------------------------------------
   Iter|sorted pref| A | C | G | A | C | T | A | C | G | A | T  | A | A | C | $ |
   ------------------------------------------------------------------------------
   0   | 1         | 1 | 2 | 3 | 1 | 2 | 4 | 1 | 2 | 3 | 1 | 4  | 1 | 1 | 2 | 0 |
   ------------------------------------------------------------------------------
   1   | 2         | 2 | 5 | 7 | 2 | 6 | 8 | 2 | 5 | 7 | 3 | 8  | 1 | 2 | 4 | 0 |
   ------------------------------------------------------------------------------
   2   | 4         | 3 | 7 | 10| 4 | 9 | 13| 3 | 8 | 11| 5 | 12 | 1 | 2 | 6 | 0 |
   ------------------------------------------------------------------------------
   3   | 8         | 3 | 8 | 11| 5 | 10| 14| 4 | 9 | 12| 6 | 13 | 1 | 2 | 7 | 0 |
   ------------------------------------------------------------------------------

	    */

 /**
 index   0 | 1  |  2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14
 suffix 14 | 11 | 12 | 0 | 6 | 3 | 9 | 13| 1 | 7 | 4  | 2  | 8  | 10 | 5
 */
 //Let Inv[i] be Inv[i .. n], and Compare(Inv[i], Inv[j], t) (it may be equal to '=', '<', or '>')
 // be the comparison of Inv[i] and Inv[j] based on their first t symbols.

		if(A == 0)
        {
            return ArrOfChar[idx] < ArrOfChar[Suffe.idx];
        }
		else if(Inv[idx] == Inv[Suffe.idx])
        {
			return (Inv[idx+A] < Inv[Suffe.idx+A]);
		}
		else
        {
			return (Inv[idx] < Inv[Suffe.idx]);
        }
	}
	bool operator==(const Suffix& Suffe) const
	{
		return !(*this < Suffe) && !(Suffe < *this);
	}
} P[Characters];

int NewInv(int L)
{
	int start = 0, id = 0, c = 0;
	for(int i = 0; i < L; i++)
	{

        //If P[i] is not equal to P[i-1], a new bucket has started.
		if(i != 0 && !(P[i] == P[i-1]))
		{
			start = i;
			id++;
		}
		if(i != start) // if there is Inv with size larger than 1, we should continue ...
			c = 1;
		nInv[P[i].idx] = id; // Inv for suffix starting at P[i].idx is id ...
	}
	memcpy(Inv, nInv, 4 * L);
	return c;
}

void SuffixSort(int L)
{
	for(int i = 0; i < L; i++)
        {
            P[i].idx = i;
        }
	// A == 0, Sort based on first Character.
	sort(P, P + L);
	// Create initial Invs
	counter = NewInv(L);
	for(A=1;counter;A *= 2) {
		// Sort based on first 2*A symbols, assuming that we have sorted based on first H character
		sort(P, P+L);
		// Update Invs based on first 2*A symbols
		counter = NewInv(L);
    /** Open File And Save The Sorted Suffixes for Double Method */
	FILE * f;
    f = fopen("DOUBLE_SUFFIX.txt","w");
    //Characters=Number of Characters
    for(int i = 0; i < Characters; i++)
        {
        //P[i]=the sorted suffixes
		fprintf(f,"%d %d\n",i,P[i].idx);
        }
    fclose(f);
	}
}




/*******************************************************/
//Teat cases
/*****************************************************/
void Test_Cases(){

  cout<<"test 1" <<endl;SuffixArray3("ACTTGTGGATAATT$",15);
  cout<<"test 2" <<endl;SuffixArray3("TATTCATGCTCATG$",15);
  cout<<"test 3" <<endl;SuffixArray3("TTTCGAGTGATCGA$",15);
  cout<<"test 4" <<endl;SuffixArray3("AAAAAAAAAAAAAA$",15);
  cout<<"test 5" <<endl;SuffixArray3("ATTTTTTTTTTTTA$",15);
  cout<<"test 6" <<endl;SuffixArray3("ATTTCCCCGGGGAT$",15);
  cout<<"test 7" <<endl;SuffixArray3("TCGTACGTACGTAC$",15);
  cout<<"test 8" <<endl;SuffixArray3("TTTTTTTTTTTTTT$",15);
  cout<<"test 9" <<endl;SuffixArray3("AATTTCTATATGCT$",15);
  cout<<"test 10"<<endl;SuffixArray3("GAAATTGCACAATT$",15);
  cout<<"test 11"<<endl;SuffixArray3("ATCATACTGAAGTG$",15);
  cout<<"test 12"<<endl;SuffixArray3("AACAGTTAAGAGCA$",15);
  cout<<"test 13"<<endl;SuffixArray3("CAAAGACTCCGGTA$",15);
  cout<<"test 14"<<endl;SuffixArray3("ATATTTTAGAAATT$",15);
  cout<<"test 15"<<endl;SuffixArray3("TATGTGATTTATCC$",15);
  cout<<"test 16"<<endl;SuffixArray3("ATTTCGTCGTGATC$",15);
  cout<<"test 17"<<endl;SuffixArray3("GATATGTTAACAAG$",15);
  cout<<"test 18"<<endl;SuffixArray3("CACATTCTGGCAAA$",15);
  cout<<"test 19"<<endl;SuffixArray3("TTAGCCGCTTCATA$",15);
  cout<<"test 20"<<endl;SuffixArray3("AGAGATCTCATTGA$",15);
  cout<<"test 21"<<endl;SuffixArray3("GATGACCAGTGGAG$",15);
  cout<<"test 22"<<endl;SuffixArray3("TATGATACCATCTT$",15);
  cout<<"test 23"<<endl;SuffixArray3("TAAGTTGAGTAGAA$",15);
  cout<<"test 24"<<endl;SuffixArray3("AGATAATGTTTTAA$",15);
  cout<<"test 25"<<endl;SuffixArray3("ATGTAAAAGTTTCA$",15);
  cout<<"test 26"<<endl;SuffixArray3("TTATGAAAACAAAA$",15);
  cout<<"test 27"<<endl;SuffixArray3("ATGGTAAATAATAA$",15);
  cout<<"test 28"<<endl;SuffixArray3("TTTAAAAATTGAAA$",15);
  cout<<"test 29"<<endl;SuffixArray3("GAGTTAGCGAAGGA$",15);
  cout<<"test 30"<<endl;SuffixArray3("GAGTTAGCGAAGGA$",15);

}


int main ( )
{
    /**to run the code just change the Dir in read 1 and read 2 and it will run */
    /** I read The File As ' ONE ' Line NOT Line By Line To Show Correct Answers */
    read();
    int leng = strlen(ArrOfChar);
    //For Naive Construct O(N^2 Log N) with 10000 Char
    SuffixArray(ArrOfChar,leng);
    //For Double Construct O (N LogN LogN)
    SuffixSort(Characters);
    read2();
    //For The Whole File
    SuffixArray2(ArrOfCha);
    Test_Cases();
    return 0;
}
