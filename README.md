#Dijkstra's Algorithm for Graphs

# MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

<h2 style = "font-size: 18px;">Introduction</h2>
<ul>
  <li>This program is designed to read a file of graph information, run Dijkstra’s Algorithm on the graph, and produce the path and the length/weight of the path between the starting Vertex and any other Vertex in the graph.We are creating a program that can read a file of graph information and run Dijkstra’s Algorithm on the graph and produce the path and the length/weight of the path between the starting Vertex and any other Vertex in the graph.</li>
</ul>

<h2 style = "font-size : 18px;">Features</h2>
<ul>
  <li>Reads a file of graph information and creates an adjacency matrix to represent the graph. </li>
  <li>Runs Dijkstra's Algorithm on the graph to find the shortest path between the starting vertex and any other vertex. </li>
  <li>Outputs the path and length/weight of the path from the starting vertex to every other vertex in the graph. </li>
  <li>Can handle graphs of up to a maximum size (defined by the user) in terms of the number of vertices.</li>
</ul>

<h2 stlye = "font-size:18px;">Getting Started: </h2>
<ul>
<li>Create a file representing the graph you wish to analyze in the following format: VertexLabel, Adjacent Vertex Index, Weight of Edge. The VertexLabel can be up to 5 characters long, and the vertices can be listed in any order in the file. </li>
<li>Save the file as "Graph.txt" and place it in the same directory as the program.</li>
<li>Compile and run the program in a C compiler of your choice. </li>
<li>Follow the instructions presented by the program to input the starting vertex and view the shortest path to every other vertex in the graph.</li>
</ul>



<h2 style = "font-size : 18px;"> Limitations: </h2>
<ul>
  <li>The program only works for directed graphs.</li>
  <li>The program assumes that the input file is well-formed and follows the specified format. Any deviations from the format may lead to undefined behavior.</li>
  <li>The program assumes that the user has correctly specified the starting vertex, otherwise the output may be inaccurate.</li>
</ul>


<h2 stlye : "font-size : 18px"> Author: </h2>
<ul><li>This program was created by Aryan Mainkar.</li></ul>

