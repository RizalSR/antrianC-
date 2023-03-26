#include <iostream> 
#include <stdlib.h> 
#include <string.h>  
using namespace std;

struct antrian {     
    int nomorAntrian;     
    char nama[30];     
    antrian *next; 
} * head, *newNode, *temporaryNode, *currentnode, *tail;

void antrianbaru(int); 
void enqueue(antrian *); 
void dequeue(); 
void cetakAntrian(); 
bool isEmpty(); 
void clear(); 

int main() {     
    head = tail = NULL;     
    char pilihan;     
    bool ongoing = true;     
    int nomorAntrian = 1;
    while (ongoing)     {         
        cout << endl;              
        cout << "=======================================" << endl;         
        cout << "      Program Antrian Klinik     " << endl;         
        cout << "=======================================" << endl;         
        cout << "1. Tambah Antrian Baru" << endl;         
        cout << "2. Panggil Antrian" << endl;         
        cout << "3. Tampilkan Antrian" << endl;         
        cout << "4. Hapus & reset Antrian" << endl;         
        cout << "5. KELUAR" << endl;         
        cout << "Pilihan [1-5]: ";         
        cin >> pilihan;         
        switch (pilihan)         {         
            case '1':
				system("CLS");           
                antrianbaru(nomorAntrian);             
                nomorAntrian++;             
                break;         
            case '2':
				system("CLS");              
                dequeue();             
                break;         
            case '3': 
				system("CLS");             
                cetakAntrian();             
                break;         
            case '4':  
				system("CLS");            
                clear();             
                nomorAntrian = 1;             
                break;         
            case '5':   
				system("CLS");           
                cout << "Program selesai." << endl;             
                ongoing = false;             
                break;         
            default:             
                cout << "Input Salah." << endl;             
                break;         }     }     
    return 0; 
    
}
void antrianbaru(int nomorAntrian)
{     
    char inputNama[30];      
    cout << "masukkan nama pasien: ";     
    cin >> inputNama;      
    newNode = new antrian();     
    newNode->nomorAntrian = nomorAntrian;     
    strcpy(newNode->nama, inputNama);     
    newNode->next = NULL;         
    enqueue(newNode); 
}

bool isEmpty() {     
    if (head == NULL){         
        return true;   
    }else{         
        return false;    
    }
}

void enqueue(antrian *newNode) {
    if (isEmpty()){       
        head = tail = newNode;     
        
    }else{                
        tail->next = newNode;
        tail = newNode;
    }     
    cout << "Nomor antrian 0" << newNode->nomorAntrian;     
    cout << " atas nama " << newNode->nama << " berhasil ditambahkan." << endl;
}
void dequeue(){     
    if (isEmpty()){         
        cout << "Antrian Kosong." << endl;
    }else{
        currentnode = head;
        cout << "Nomor antrian 0" << currentnode->nomorAntrian;
        cout << " atas nama " << currentnode->nama << " keluar." << endl;
        head = head->next;
    }
} 
void cetakAntrian() {
    cout << "\n=================" << endl;
    cout << "     Antrian     " << endl;
    cout << "=================" << endl;
    if (isEmpty()){
        cout << "Antrian Kosong." << endl;
    }else{
        currentnode = head;         
        cout << "NO  Nama" << endl;
        while (currentnode != NULL){
            cout << currentnode->nomorAntrian << ".  " << currentnode->nama << endl;
            currentnode = currentnode->next; 
        }        
        cout << "=================" << endl;
    } 
}

void clear() {     
    currentnode = head;     
    while (currentnode != NULL)     
    {         
        temporaryNode = currentnode;         
        temporaryNode->next = NULL;         
        currentnode = currentnode->next;
    }     
    head = NULL;     
    temporaryNode == NULL;     
    cout << "Antrian telah dihapus dan di-reset ke semula." << endl; 
}
