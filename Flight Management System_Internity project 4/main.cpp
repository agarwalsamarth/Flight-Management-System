#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    // number of vertices
    int n=9;

    // adjacency matrix


    pair<int,int> A[15][15] = { { {0,0}, {4,70}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {8,30}, {0,0} },
                             { {4,70}, {0,0}, {8,40}, {0,0}, {0,0}, {0,0}, {0,0}, {11,50}, {0,0} },
                             { {0,0}, {8,100}, {0,0}, {7,70}, {0,0}, {4,20}, {0,0}, {0,0}, {2,40} },
                             { {0,0}, {0,0}, {7,100}, {0,0}, {9,90}, {14,120}, {0,0}, {0,0}, {0,0} },
                             { {0,0}, {0,0}, {0,0}, {9,70}, {0,0}, {10,110}, {0,0}, {0,0}, {0,0} },
                             { {0,0}, {0,0}, {4,50}, {14,170}, {10,120}, {0,0}, {2,40}, {0,0}, {0,0} },
                             { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {2,70}, {0,0}, {1,30}, {6,60} },
                             { {8,90}, {11,80}, {0,0}, {0,0}, {0,0}, {0,0}, {1,20}, {0,0}, {7,70} },
                             { {0,0}, {0,0}, {2,20}, {0,0}, {0,0}, {0,0}, {6,20}, {7,60}, {0,0} } };



    int f[15][15]=      { { 0, 30, 0, 0, 0, 0, 0, 80, 0 },
                        { 70, 0, 40, 0, 0, 0, 0, 100, 0 },
                        { 0, 80, 0, 70, 0, 20, 0, 0, 40 },
                        { 0, 0, 60, 0, 90, 120, 0, 0, 0 },
                        { 0, 0, 0, 80, 0, 110, 0, 0, 0 },
                        { 0, 0, 50, 110, 120, 0, 40, 0, 0 },
                        { 0, 0, 0, 0, 0, 20, 0, 30, 60 },
                        { 90, 80, 0, 0, 0, 0, 20, 0, 70 },
                        { 0, 0, 20, 0, 0, 0, 80, 60, 0 } };

public:
    //To display both adjacency matrices
    void displayAdjacencyMatrix()
    {
        // displaying the 2D array
        cout<<"\nAdjacency matrix of pair<distance,fare>:\n";
        for (int i = 0; i < n; ++i) {
            cout << "\n";
            for (int j = 0; j < n; ++j) {
                cout << "\t" << A[i][j].first<<" "<<A[i][j].second;
            }
        }
        cout<<"\n\n";
    }

    // 1) To add an airport
    void addAirport()
    {
        // increasing the number of vertices
        n++;
        int i;

        // initializing the new elements to 0
        for (i = 0; i < n; ++i) {
            A[i][n - 1].first = 0;
            A[n - 1][i].first = 0;
            A[i][n - 1].second = 0;
            A[n - 1][i].second = 0;
        }
        cout<<"\nNew Airport Added!!\n";
        displayAdjacencyMatrix();
    }


    // 2) To remove an airport
    void removeAirport()
    {
        int x;
        cout<<"Which airport do you want to remove\n";
        cin>>x;
        // checking if the vertex is present
        if (x > n)
        {
            cout << "\nVertex not present!";
            return;
        }
        else
        {
            int i;
            // removing the vertex
            while (x < n)
            {
                // shifting the rows to left side
                for (i = 0; i < n; ++i) {
                    A[i][x].first = A[i][x + 1].first;
                    A[i][x].second = A[i][x + 1].second;
                }

                // shifting the columns upwards
                for (i = 0; i < n; ++i) {
                    A[x][i].first = A[x + 1][i].first;
                    A[x][i].second = A[x + 1][i].second;
                }
                x++;
            }
            // decreasing the number of vertices
            n--;
        }
        displayAdjacencyMatrix();
    }



    // 3) To add a route between 2 airport
    void addRoute()
    {
        int x,y,dist,fare;
        cout<<"Enter vertex between whose edge is to be added\n";
        cin>>x>>y;
        cout<<"Enter distance and fare\n";
        cin>>dist>>fare;
        // checks if the vertex exists in the graph
        if ((x >= n) || (y > n)) {
            cout << "Vertex does not exists!";
        }

        // checks if the vertex is connecting to itself
        if (x == y) {
            cout << "Same Vertex!";
        }
        else {
            // connecting the vertices
            A[y][x].first = dist;
            A[x][y].first = dist;
            A[y][x].second = fare;
            A[x][y].second = fare;
        }

        displayAdjacencyMatrix();
    }



    // 4) To delete a route between 2 airport
    void deleteroute(){
        int x,y;
        cout<<"Enter Vertex between whose vertex is to be delete\n";
        cin>>x>>y;
        if ((x>=n) or (y>n)){
            cout<<"Vertex doesn't exists!";
        }
        else{
            A[y][x].first=0;
            A[x][y].first=0;
            A[x][y].second=0;
            A[y][x].second=0;
        }
        displayAdjacencyMatrix();
    }



    // 5) To update fare & distance of a route
    void updateFnD(){
        int x,y,dist,fare;
        cout<<"Enter vertex between whose distance is to be update\n";
        cin>>x>>y;
        cout<<"Enter new distance and fare\n";
        cin>>dist>>fare;
        if ((x >= n) || (y > n)) {
            cout << "Vertex does not exists!";
        }
        if (x == y) {
            cout << "Same Vertex!";
        }
        else {

            A[y][x].first = dist;
            A[x][y].first = dist;
            A[y][x].second = fare;
            A[x][y].second = fare;
        }
        displayAdjacencyMatrix();
    }



    int minDistance(int dist[], bool sptSet[])
    {
        // Initialize min value
        int min = INT_MAX, min_index;

        for (int v = 0; v < n; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;

        return min_index;
    }


    // 6) To calculate single source to single destination shortest path
    void s2d_dist()
    {
        int src,dest;
        cout<<"\nEnter source and destination node\n";
        cin>>src>>dest;
        int dist[n]; // The output array.  dist[i] will hold the shortest
        // distance from src to i

        bool sptSet[n]; // sptSet[i] will be true if vertex i is included in shortest
        // path tree or shortest distance from src to i is finalized

        // Initialize all distances as INFINITE and stpSet[] as false
        for (int i = 0; i < n; i++)
            dist[i] = INT_MAX, sptSet[i] = false;

        // Distance of source vertex from itself is always 0
        dist[src] = 0;

        // Find shortest path for all vertices
        for (int count = 0; count < n - 1; count++)
        {
            // Pick the minimum distance vertex from the set of vertices not
            // yet processed. u is always equal to src in the first iteration.
            int u = minDistance(dist, sptSet);

            // Mark the picked vertex as processed
            sptSet[u] = true;

            // Update dist value of the adjacent vertices of the picked vertex.
            for (int v = 0; v < n; v++)

                // Update dist[v] only if is not in sptSet, there is an edge from
                // u to v, and total weight of path from src to  v through u is
                // smaller than current value of dist[v]
                if (!sptSet[v] && A[u][v].first && dist[u] != INT_MAX
                    && dist[u] + A[u][v].first < dist[v])
                    dist[v] = dist[u] + A[u][v].first;
        }

        cout<<"\nMinimum distance from "<<src<<" to "<<dest<<" = ";
        cout<<dist[dest]<<"\n\n";
        s2d_fare(src,dest);
    }

    void s2d_fare(int src,int dest)
    {
        int dist[n]; // The output array.  dist[i] will hold the shortest
        // distance from src to i
        int parent[n];

        bool sptSet[n]; // sptSet[i] will be true if vertex i is included in shortest
        // path tree or shortest distance from src to i is finalized

        // Initialize all distances as INFINITE and stpSet[] as false
        for (int i = 0; i < n; i++)
            dist[i] = INT_MAX, sptSet[i] = false;

        // Distance of source vertex from itself is always 0
        dist[src] = 0;
        //parent[src]=0;
        // Find shortest path for all vertices
        for (int count = 0; count < n - 1; count++) {
            // Pick the minimum distance vertex from the set of vertices not
            // yet processed. u is always equal to src in the first iteration.
            int u = minDistance(dist, sptSet);

            // Mark the picked vertex as processed
            sptSet[u] = true;

            // Update dist value of the adjacent vertices of the picked vertex.
            for (int v = 0; v < n; v++)

                // Update dist[v] only if is not in sptSet, there is an edge from
                // u to v, and total weight of path from src to  v through u is
                // smaller than current value of dist[v]
                if (!sptSet[v] && A[u][v].second && dist[u] != INT_MAX
                    && dist[u] + A[u][v].second < dist[v])
                    {
                        dist[v] = dist[u] + A[u][v].second;
         //               parent[v]=parent[u] + A[u][v].first;
                    }

        }

        cout<<"Minimum fare from "<<src<<" to "<<dest<<" = ";
        cout<<dist[dest]<<"\n\n";

       // cout<<"Total distance from "<<src<<" to "<<dest<<" = ";
       // cout<<parent[dest]<<"\n\n";
    }



    // 7) Single source to all nodes shortest path
    void s2ad_dist()
    {
        int src;
        cout<<"\nEnter source node\n";
        cin>>src;
        int dist[n]; // The output array.  dist[i] will hold the shortest
        // distance from src to i

        bool sptSet[n]; // sptSet[i] will be true if vertex i is included in shortest
        // path tree or shortest distance from src to i is finalized

        // Initialize all distances as INFINITE and stpSet[] as false
        for (int i = 0; i < n; i++)
            dist[i] = INT_MAX, sptSet[i] = false;

        // Distance of source vertex from itself is always 0
        dist[src] = 0;

        // Find shortest path for all vertices
        for (int count = 0; count < n - 1; count++) {
            // Pick the minimum distance vertex from the set of vertices not
            // yet processed. u is always equal to src in the first iteration.
            int u = minDistance(dist, sptSet);

            // Mark the picked vertex as processed
            sptSet[u] = true;

            // Update dist value of the adjacent vertices of the picked vertex.
            for (int v = 0; v < n; v++)

                // Update dist[v] only if is not in sptSet, there is an edge from
                // u to v, and total weight of path from src to  v through u is
                // smaller than current value of dist[v]
                if (!sptSet[v] && A[u][v].first && dist[u] != INT_MAX
                    && dist[u] + A[u][v].first < dist[v])
                    dist[v] = dist[u] + A[u][v].first;
        }

        // print the constructed distance array
        cout<<"\nOn basis of Shortest path\n";
        for (int i = 0; i < n; i++)
            cout<<i<<" -> "<<dist[i]<<"\n";

        s2ad_fare(src);
    }

    void s2ad_fare(int src)
    {
        int dist[n]; // The output array.  dist[i] will hold the shortest
        // distance from src to i

        bool sptSet[n]; // sptSet[i] will be true if vertex i is included in shortest
        // path tree or shortest distance from src to i is finalized

        // Initialize all distances as INFINITE and stpSet[] as false
        for (int i = 0; i < n; i++)
            dist[i] = INT_MAX, sptSet[i] = false;

        // Distance of source vertex from itself is always 0
        dist[src] = 0;

        // Find shortest path for all vertices
        for (int count = 0; count < n - 1; count++) {
            // Pick the minimum distance vertex from the set of vertices not
            // yet processed. u is always equal to src in the first iteration.
            int u = minDistance(dist, sptSet);

            // Mark the picked vertex as processed
            sptSet[u] = true;

            // Update dist value of the adjacent vertices of the picked vertex.
            for (int v = 0; v < n; v++)

                // Update dist[v] only if is not in sptSet, there is an edge from
                // u to v, and total weight of path from src to  v through u is
                // smaller than current value of dist[v]
                if (!sptSet[v] && A[u][v].second && dist[u] != INT_MAX
                    && dist[u] + A[u][v].second < dist[v])
                    dist[v] = dist[u] + A[u][v].second;
        }

        // print the constructed distance array
        cout<<"\nOn basis of Minimum fare\n";
        for (int i = 0; i < n; i++)
            cout<<i<<" -> "<<dist[i]<<"\n";
        cout<<"\n";
    }



    // 8) All nodes to all nodes shortest path
    void an2ad()
    {
        int src;
        for(int src=0;src<n;src++)
        {
            cout<<"\nSource node is " <<src<<endl;
            //cin>>src;
            int dist[n]; // The output array.  dist[i] will hold the shortest
            // distance from src to i

            bool sptSet[n]; // sptSet[i] will be true if vertex i is included in shortest
            // path tree or shortest distance from src to i is finalized

            // Initialize all distances as INFINITE and stpSet[] as false
            for (int i = 0; i < n; i++)
                dist[i] = INT_MAX, sptSet[i] = false;

            // Distance of source vertex from itself is always 0
            dist[src] = 0;

            // Find shortest path for all vertices
            for (int count = 0; count < n - 1; count++) {
                // Pick the minimum distance vertex from the set of vertices not
                // yet processed. u is always equal to src in the first iteration.
                int u = minDistance(dist, sptSet);

                // Mark the picked vertex as processed
                sptSet[u] = true;

                // Update dist value of the adjacent vertices of the picked vertex.
                for (int v = 0; v < n; v++)

                    // Update dist[v] only if is not in sptSet, there is an edge from
                    // u to v, and total weight of path from src to  v through u is
                    // smaller than current value of dist[v]
                    if (!sptSet[v] && A[u][v].first && dist[u] != INT_MAX
                        && dist[u] + A[u][v].first < dist[v])
                        dist[v] = dist[u] + A[u][v].first;
            }

            // print the constructed distance array
            cout<<"On basis of shortest path\n";
            for (int i = 0; i < n; i++)
                cout<<i<<" -> "<<dist[i]<<"\n";

            cout<<endl;
            s2ad_fare(src);
            cout<<endl;
        }
    }



    // 9) all nodes to all nodes minimum fare route
    void af2ad()
        {
            int src;
            for(int src=0;src<n;src++)
            {
            cout<<"\nSource node is " <<src<<endl;
            //cin>>src;
            int fare[n]; // The output array.  dist[i] will hold the shortest
            // distance from src to i

            bool sptSet[n]; // sptSet[i] will be true if vertex i is included in shortest
            // path tree or shortest distance from src to i is finalized

            // Initialize all distances as INFINITE and stpSet[] as false
            for (int i = 0; i < n; i++)
                fare[i] = INT_MAX, sptSet[i] = false;

            // Distance of source vertex from itself is always 0
            fare[src] = 0;

            // Find shortest path for all vertices
            for (int count = 0; count < n - 1; count++) {
                // Pick the minimum distance vertex from the set of vertices not
                // yet processed. u is always equal to src in the first iteration.
                int u = minDistance(fare, sptSet);

                // Mark the picked vertex as processed
                sptSet[u] = true;

                // Update dist value of the adjacent vertices of the picked vertex.
                for (int v = 0; v < n; v++)

                    // Update dist[v] only if is not in sptSet, there is an edge from
                    // u to v, and total weight of path from src to  v through u is
                    // smaller than current value of dist[v]
                    if (!sptSet[v] && A[u][v].second && fare[u] != INT_MAX
                        && fare[u] + A[u][v].second < fare[v])
                        fare[v] = fare[u] + A[u][v].second;
            }

            // print the constructed distance array
            for (int i = 0; i < n; i++)
                cout<<i<<" -> "<<fare[i]<<"\n";

                cout<<endl;
        }
    }
    void choice()
    {
        int w;
        cout<<"Enter your choice"<<endl<<"enter 1 for minimum timing"<<endl<<"enter 2 for minimum fare\n";
        cin>>w;
        if(w==1)
        an2ad();
        if(w==2)
        af2ad();

    }
};



int main()
{
    Graph obj;
    cout<<"\n*********************** Welcome To Flight Management System ***********************\n";
    cout<<"                        -----------------------------------                        \n";
    obj.displayAdjacencyMatrix();
    while(1)
    {
        int ch;
        cout<<"Enter 0 to exit\n";
        cout<<"Enter 1 for addition of airport\n";
        cout<<"Enter 2 for removal of airport\n";
        cout<<"Enter 3 for addition of route\n";
        cout<<"Enter 4 for removal of route\n";
        cout<<"Enter 5 for updation of route fare and distance\n";
        cout<<"Enter 6 for source to destination shortest path algorithm\n";
        cout<<"Enter 7 for single source to all nodes shortest path\n";
        cout<<"Enter 8 for all nodes to all nodes shortest path\n";
        cout<<"Enter 9 for shortest path on bases of choice by user (fare or distance)\n";
        cout<<"Enter a choice\n";
        cin>>ch;
        switch(ch)
        {
            case 0:
                cout<<"You have opted to EXIT"<<endl;
                exit(0);
            case 1:
                obj.addAirport();
                break;
            case 2:
                obj.removeAirport();
                break;
            case 3:
                obj.addRoute();
                break;
            case 4:
                obj.deleteroute();
                break;
            case 5:
                obj.updateFnD();
                break;
            case 6:
                obj.s2d_dist();
                break;
            case 7:
                obj.s2ad_dist();
                break;
            case 8:
                obj.an2ad();
			    break;
			case 9:
			    obj.choice();
			    break;
        }
    }
    return 0;
}
