#Dijkstra's Algorithm for Graphs

Introduction:
This program is designed to read a file of graph information, run Dijkstra’s Algorithm on the graph, and produce the path and the length/weight of the path between the starting Vertex and any other Vertex in the graph.We are creating a program that can read a file of graph information and run Dijkstra’s Algorithm on the graph and produce the
path and the length/weight of the path between the starting Vertex and any other Vertex in the graph.

Features:

Reads a file of graph information and creates an adjacency matrix to represent the graph.
Runs Dijkstra's Algorithm on the graph to find the shortest path between the starting vertex and any other vertex.
Outputs the path and length/weight of the path from the starting vertex to every other vertex in the graph.
Can handle graphs of up to a maximum size (defined by the user) in terms of the number of vertices.
Getting Started:

Create a file representing the graph you wish to analyze in the following format: VertexLabel, Adjacent Vertex Index, Weight of Edge. The VertexLabel can be up to 5 characters long, and the vertices can be listed in any order in the file.
Save the file as "Graph.txt" and place it in the same directory as the program.
Compile and run the program in a C compiler of your choice.
Follow the instructions presented by the program to input the starting vertex and view the shortest path to every other vertex in the graph.
Limitations:

The program only works for directed graphs.
The program assumes that the input file is well-formed and follows the specified format. Any deviations from the format may lead to undefined behavior.
The program assumes that the user has correctly specified the starting vertex, otherwise the output may be inaccurate.
Author:
This program was created by [insert your name here] for the CSE3318 course at [insert your university here].
