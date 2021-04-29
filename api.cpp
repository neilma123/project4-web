//  Project UID c1f28c309e55405daf00c565d57ff9ad
//  api.cpp
//  p4server
//
//  Created by Adam Douglas Mentzer and Neil "Thunder" Mascarenhas on 3/29/21.
//
#include <iostream>
#include <string>
#include <cmath>
#include <list>
#include "json.hpp"
using namespace std;
using nlohmann::json;

/*
 Next, the server receives the request sent by the client. The server acts on the request.
 Here’s an outline of how to structure your solution.
 
 Read a request with cin
 To read data, create a temporary json object and use cin (Reading JSON from a stream)
 Read or write the list data structure
 Write a response with cout
 To write data, create a temporary json object and use cout (Writing JSON to a stream)
 --
 Deserialize the JSON data, converting it into a data structure
 Modify an internal data structure, possibly a list
 Create a response data structure
 Serialize the response data structure, converting it to JSON
 Send the response to the client
 The response to the client might look like this.
 */

json ableAccess = {
    {"queue_head_url", "http://localhost/queue/head/"},
    {"queue_list_url", "http://localhost/queue/"},
    {"queue_tail_url", "http://localhost/queue/tail/"}
};

void errorHandling(){
    
    for(int i = 0; i < 7; ++i){
        string junkmeme;
        cin >> junkmeme;
    }
    
    int contentsize; cin >> contentsize;
    json studentOb; cin >> studentOb;
    cout << "HTTP/1.1" << " " << 400 << " " << "Bad Request" << endl;
    cout << "Content-Type: application/json; charset=utf-8" << endl;
    cout << "Content-Length: " << 0 << endl << endl;
}

class OHQueue {
    
private:
    struct Student {
        string location;
        int position;
        string uniqname;
    };
    
    list <Student> queue;
    
    
public:
    
    int getsize(){return (int) queue.size();}
    
    void pushBackOH(json SimpleSimon){
        Student s;
        s.location = SimpleSimon["location"];
        s.position = SimpleSimon["position"];
        s.uniqname = SimpleSimon["uniqname"];
        queue.push_back(s);
    }
    //xcode redirection
    void popFrontOH(){queue.pop_front();}
    
    bool queueEmpty(){return queue.empty();}
    
    Student OHfront(){return queue.front();}
    
    json transposeStudent(Student Ted){
        
        json TedJason = {
            {"location", Ted.location},
            {"position", Ted.position},
            {"uniqname", Ted.uniqname}
        };
        
        return TedJason;
    }
    
    Student OHback(){return queue.back();}
    
    int getContentsize(json P){
        //get json object (studentOb), dump to string (append \n), do string size
        json tempStudent = P;
        string tempSizeStudent = tempStudent.dump(4) + "\n";
        int studentContent = (int) tempSizeStudent.size();
        return studentContent;
    }
    
    //
    
    void printQueue(){
        string jsonDump;
        int countJSON = 0;
        json jArray;
        size_t content_length = 0;
        for(list <Student>::iterator i = queue.begin(); i != queue.end(); ++i){
            json getDumped = transposeStudent(*i);
            jArray.push_back(getDumped);
            countJSON+=1;
        }
        
        json jMassive = {
            {"count", countJSON},
            {"results", jArray}
        };
        jsonDump = jMassive.dump(4) + "\n";
        content_length = jsonDump.length();
        
        cout << "HTTP/1.1 200 OK" << endl;
        cout << "Content-Type: application/json; charset=utf-8" << endl;
        cout << "Content-Length: " << content_length << endl << endl;
        cout << jsonDump;
        
        //-----------
    }
    void getHead(){
        cout << "HTTP/1.1 200 OK" << endl;
        cout << "Content-Type: application/json; charset=utf-8" << endl;
        json frontStudent = transposeStudent(OHfront());
        cout << "Content-Length: " << getContentsize(frontStudent)
        << endl << endl;
        string getDump = frontStudent.dump(4) + "\n";
        cout << getDump;
    }
    void getAPI(){
        cout << "HTTP/1.1 200 OK" << endl;
        cout << "Content-Type: application/json; charset=utf-8" << endl;
        cout << "Content-Length: 160" << endl << endl;
        string validURL = ableAccess.dump(4) + "\n";
        cout << validURL;
    }
    void readPOST(json &studentOb, istream &cin){
        cin >> studentOb;
        int pos = getsize() + 1;
        studentOb["position"] = pos;
        pushBackOH(studentOb);
        cout << "HTTP/1.1 201 Created" << endl;
        cout << "Content-Type: application/json; charset=utf-8" << endl;
        cout << "Content-Length: " <<
        getContentsize(studentOb) << endl;
        cout << endl;
        string tempOb = studentOb.dump(4) + "\n";
        cout << tempOb;
    }
    void printDelete(){
        cout << "HTTP/1.1 204 No Content"<<endl;
        cout << "Content-Type: application/json; charset=utf-8" << endl;
        cout << "Content-Length: 0"  << endl << endl;
    }
    void methodGET(string endtail){
        if(endtail == "/api/queue/head/"){
            if(queueEmpty()){errorHandling();}
            else {
                getHead();
                
            }
        }
        else if(endtail == "/api/queue/"){
            printQueue();
            
        }
        else if(endtail == "/api/"){
            getAPI();
            
        }
        else{
            errorHandling();
            
        }
    }
};

int main(){
    string method;
    OHQueue OHQ;
    while(cin >> method){
        string endtail;
        cin >> endtail;
        if(method == "GET"){
            OHQ.methodGET(endtail);
            continue;
        }
        else if(method == "POST" && endtail == "/api/queue/tail/"){
                for(int i = 0; i < 7; ++i){
                    string junkMeme;
                    cin >> junkMeme;
                }
                int contentsize;
                json studentOb;
                if(cin >>contentsize && contentsize != 0){
                    OHQ.readPOST(studentOb, cin);
                    continue;
                }
            }
        else if(method == "POST" && endtail !="/api/queue/tail/"){
            errorHandling();
            continue;
        }
       else if(method == "DELETE"){
            if(endtail == "/api/queue/head/"){
                OHQ.popFrontOH();
                OHQ.printDelete();
                continue;
            }
            else if(endtail != "/api/queue/head/"){
                errorHandling();
                continue;
            }
        }
    }
}
