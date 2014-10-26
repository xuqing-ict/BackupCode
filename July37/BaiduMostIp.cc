#include <bits/stdc++.h>
using namespace std;

const int N=32; //32 temp files to store the ip address
#define ID(x) ((x)>>27) //file index
#define VALUE(x) ((x)&(0x07ffffff))
#define MAKE_IP(x,y) (((x)<<27)|(y))

const int MAX_IP_COUNT_IN_MEM = 128*1024*1024; //128M¸öIPµØÖ·£¡£¡

string log_file = "./Log";
void generate_IP(const int n) // generate n ips
{
    ofstream out(log_file.c_str());
    srand((unsigned)time(NULL));
    if(out)
    {
        for(int i=0;i<n;++i)
        {
            unsigned int val=unsigned(rand());
            val=(val<<24)|val;
            //out << val << endl;
            out.write((char *)&val,sizeof(unsigned));
            out.write((char *)&val,sizeof(unsigned));
            out.write((char *)&val,sizeof(unsigned));
            out.write((char *)&val,sizeof(unsigned));
        }
    }
    out.close();
    out.clear();
}

void findLargestIP(const int n) // n ips
{
    cout << "divide " << N << " groups..." << endl;
    fstream arr[N];
    //create N temp files
    for(int i=0;i < N; ++i) //N groups
    {
        char temp_file[100];
        sprintf(temp_file,"D:/xq/JULY/tmp%d.dat",i);
        arr[i].open(temp_file);//ios::trunc|ios::in|ios::out|ios::binary);
        if(!arr[i]) {cerr << "create file error... " <<i<< endl;exit(1);}
    }
    cout << "set temp file" << endl;
    //read ip address and set the temp files
    ifstream in(log_file.c_str());
    unsigned int data;
    while(in.read((char *)&data,sizeof(data)))
    {
        int key=ID(data);
        int value=VALUE(data);
        //arr[key] << value << endl;
        arr[key].write((char *) &value,sizeof(value));
    }
cout << "set temp file end" << endl;
    //read the file from beginning
    for(int i=0;i<N;++i) arr[i].seekg(0);

    unsigned int max_ip=0,max_count=0;
    unsigned int *Count=new unsigned int[MAX_IP_COUNT_IN_MEM];

    for(int i=0; i < N ; ++i) //read each file
    {
        memset(Count,0,sizeof(unsigned)*MAX_IP_COUNT_IN_MEM);
        unsigned int ip;
        while(arr[i].read((char*)&ip,sizeof(unsigned)))
        {
            ++Count[ip];
        }
        for(unsigned j=0;j<MAX_IP_COUNT_IN_MEM;++j)
        {
            if(max_count < Count[j])
            {
                max_count=Count[j];
                max_ip=MAKE_IP(i,j);
            }
        }
    }
    delete [] Count;
    cout <<max_ip <<"\t" <<max_count << endl;
    unsigned char *res = (unsigned char *)(&max_ip);
    printf("Most ip address : %d.%d.%d.%d : %d\n",res[0],res[1],res[2],res[3],max_count);
}
int main(void)
{
    int n;
    cin >> n;
    generate_IP(n);
    findLargestIP(n);
    return 0;
}
