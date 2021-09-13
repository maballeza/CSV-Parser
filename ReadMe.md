## CSV-Parser
### Overview
A soon to be generalized **.csv** parser capable of producing objects on which statistical analysis can be performed.
  > *Universities* currently parses data ranking top universities worldwide and optionally performs one form of analysis, printing either the results of the analysis or the parsed list of data.

### Building
The project must be built using the C++17 standard; the build directory must also contain an ***Out*** directory into which the results of computations are issued.

### Usage
When prompted, selecting option `1` will return a complete list of summaries for each item listed in the **.csv**; option `2` will proceed to compute an average for a range of entries from the **.csv** once it has obtained the (zero-based) starting and ending indices needed for computation; an input of `0` terminates the program.

#### To be continued...
- Additional analytical methods are soon to be added.
- Implemention of template methods are in the works to remove **dependencies** on class *University*