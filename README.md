<h3><b>Traffic Classifier</b></h3></hr>



<h3><b>Requirements and Dependencies</b></h3>
</hr>

Traffic Classifier was written in C++ and requires the pre-installation of libpcap library. This mechanism was developed under linux environment and is only able to run in this environment. The libPcapWrap.so (available in lib folder) needs to be also included in the project. 
This library is responsible to manage packets captured directly from the network interface or readfrom the file. The packets classes are also included in this library.

<h4><b>User Manual and Minimal Example</b></h4>
</hr>


<h3>References</h3>

For detailed information about this classifier, please take a look to the following publications:

<ul>
<li>
Miguel Neto, João V. Gomes, Mário M. Freire, and Pedro R. M. Inácio, 
<a href="http://ieeexplore.ieee.org/xpl/articleDetails.jsp?arnumber=6528276">Real-Time Traffic Classification Based on Statistical Tests for Matching Signatures with Packet Length Distributions</a>, 
in Proceedings of the 19th IEEE International Workshop on Local and Metropolitan Area Networks (IEEE LANMAN 2013), Brussels, Belgium, April 10-12, 2013, 6 pages.
</li>
</ul>