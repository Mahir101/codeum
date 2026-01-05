# Real-World Algorithm Applications

This document details how the 300+ algorithms in this library are used by top tech companies and in production systems worldwide.

---

## Table of Contents

- [Graph Theory Algorithms](#graph-theory-algorithms) (90 algorithms)
- [Data Structures](#data-structures) (62 implementations)
- [Dynamic Programming Optimizations](#dynamic-programming-optimizations) (22 techniques)
- [Math & Linear Algebra](#math--linear-algebra) (60 algorithms)
- [String Algorithms](#string-algorithms) (24 implementations)
- [Number Theory](#number-theory) (74 algorithms)
- [Geometry, Game Theory & Miscellaneous](#geometry-game-theory--miscellaneous)

---

## Graph Theory Algorithms

### Core Traversal & Search

#### BFS (Breadth-First Search)
**Real-World Uses:**
- **Facebook**: Friend suggestion system - finding shortest connection paths between users
- **LinkedIn**: "People You May Know" feature - exploring network connections level by level
- **Google Crawler**: Web indexing - discovering linked pages systematically
- **Cisco Routers**: Network packet routing - finding shortest hop paths

**Why BFS?**: Guarantees shortest path in unweighted graphs, memory-efficient for wide graphs.

#### DFS (Depth-First Search)
**Real-World Uses:**
- **GitHub**: Dependency resolution - detecting circular dependencies in packages
- **Amazon**: Product recommendation trees - exploring deep category hierarchies
- **Compiler Design**: Dead code elimination - traversing control flow graphs
- **Maze Solving**: Robotics path planning - exploring all possible routes

**Why DFS?**: Memory-efficient for deep graphs, natural recursion fit for tree structures.

---

### Shortest Path Algorithms

#### Dijkstra's Algorithm
**Real-World Uses:**
- **Google Maps**: Turn-by-turn navigation - finding fastest route considering road types
- **Uber/Lyft**: Dynamic pricing zones - calculating optimal pickup/dropoff routes
- **WhatsApp**: Message routing - finding lowest latency path through servers
- **Airlines**: Flight routing - minimizing fuel costs across waypoints

**Why Dijkstra?**: Optimal for non-negative weights, efficient with heap, real-time performance.

#### Bellman-Ford Algorithm
**Real-World Uses:**
- **Network Telecommunications**: Distance-vector routing (RIP protocol) - handling link cost changes
- **Currency Arbitrage**: Detecting profitable exchange cycles - negative weight cycle detection
- **Border Gateway Protocol (BGP)**: Internet routing - handling complex policy weights
- **Economic Models**: Market equilibrium detection - negative cost cycle identification

**Why Bellman-Ford?**: Handles negative weights, detects arbitrage opportunities.

#### Floyd-Warshall Algorithm
**Real-World Uses:**
- **Cloud Computing**: Data center network optimization - precomputing all-pairs shortest paths
- **Game Development**: NPC pathfinding - building distance matrices for AI movement
- **Social Network Analysis**: Influence propagation - computing shortest paths between all users
- **Logistics**: Warehouse placement - finding optimal distribution centers

**Why Floyd-Warshall?**: Efficient for dense graphs, simple implementation, all-pairs solution.

#### A* Search (Dijkstra variant)
**Real-World Uses:**
- **GPS Navigation**: Real-time route guidance - using geographic heuristics
- **Game AI**: Character pathfinding in Starcraft, Age of Empires - goal-directed search
- **Robotics**: Motion planning - combining cost and goal distance
- **15-Puzzle Solvers**: AI problem solving - using Manhattan distance heuristic

**Why A*?**: Much faster than Dijkstra with good heuristics, optimal and complete.

#### Johnson's Algorithm
**Real-World Uses:**
- **Sparse Network Analysis**: Social network metrics - efficient all-pairs for sparse graphs
- **Reweighting Techniques**: Algorithm optimization - preprocessing for negative weights
- **Research Tools**: Graph theory computations - combining Bellman-Ford + Dijkstra benefits

**Why Johnson's?**: O(V²log V + VE) beats Floyd-Warshall for sparse graphs.

---

### Network Flow & Matching

#### Max Flow (Dinic's/Ford-Fulkerson)
**Real-World Uses:**
- **Netflix/YouTube**: CDN bandwidth optimization - maximizing content delivery throughput
- **Amazon**: Supply chain logistics - maximizing goods flow through warehouses
- **Airlines**: Airline scheduling - maximizing passengers through hub airports
- **Image Segmentation**: Computer vision (Adobe, medical imaging) - min-cut for object detection
- **Network Security**: Intrusion detection - analyzing traffic bottlenecks

**Why Max Flow?**: Models capacity constraints, polynomial time guarantee, versatile applications.

#### Min-Cost Max-Flow (MCMF)
**Real-World Uses:**
- **Delivery Services**: UPS, FedEx route optimization - minimizing cost while meeting demand
- **Telecommunications**: AT&T, Verizon network design - balancing cost and bandwidth
- **Manufacturing**: Assembly line optimization - minimizing production costs
- **Cloud Services**: AWS EC2 placement - minimizing data transfer costs

**Why MCMF?**: Optimizes both quantity and cost, handles complex constraints.

#### Maximum Matching (Hopcroft-Karp, Hungarian, Blossom)
**Real-World Uses:**
- **Uber/Lyft**: Driver-rider matching - bipartite matching for optimal pairings
- **Tinder/Dating Apps**: User matching - maximizing compatibility connections
- **LinkedIn**: Job-candidate matching - weighted bipartite matching
- **Organ Donation**: Hospital coordination - time-critical optimal assignment
- **AdTech**: Google Ads auction - matching ads to queries with bid optimization
- **Chess Tournaments**: Player pairing - ensuring fair matchups

**Why Different Matching Algorithms?**
- **Hopcroft-Karp**: Fastest for unweighted bipartite (O(E√V)) - used when speed matters
- **Hungarian**: Weighted bipartite, cost optimization - used for job assignment
- **Blossom (Edmonds)**: General graphs (non-bipartite) - used for complex matching

#### Kuhn's Algorithm (Simpler Matching)
**Real-World Uses:**
- **Educational Systems**: Student-course assignment - simple efficient matching
- **Resource Allocation**: Task-worker assignment in smaller systems
- **Contest Platforms**: Codeforces, LeetCode judge assignment - simple but effective

**Why Kuhn's?**: Simpler to implement, sufficient for many practical cases.

---

### Minimum Spanning Tree (MST)

#### Kruskal's MST
**Real-World Uses:**
- **Telecommunications**: AT&T, Verizon network cable layout - minimizing wire length
- **Electrical Grid**: Power company infrastructure - minimizing transmission costs
- **Circuit Design**: PCB trace routing - reducing copper usage
- **Clustering**: Machine learning (k-means initialization) - grouping similar data points

**Why Kruskal?**: Works well with sorted edges, easy to implement with Union-Find.

#### Prim's MST
**Real-World Uses:**
- **Network Design**: LAN cable installation - growing network from central node
- **Approximation Algorithms**: TSP approximation - used in delivery route planning
- **Wireless Networks**: Sensor network topology - ensuring connectivity

**Why Prim?**: Better for dense graphs, natural heap-based implementation.

#### Boruvka's MST
**Real-World Uses:**
- **Parallel Computing**: Distributed MST computation - inherently parallelizable
- **VLSI Design**: Chip layout optimization - hierarchical construction
- **Geographic Information Systems**: Road network simplification

**Why Boruvka?**: Parallel-friendly, useful in distributed systems.

#### Directed MST (Edmonds)
**Real-World Uses:**
- **Dependency Resolution**: Package managers (npm, pip) - building minimal dependency trees
- **Network Broadcasting**: Optimal broadcast tree construction - minimizing relay costs
- **Document Version Control**: Minimal merge tree construction

**Why Directed MST?**: Handles directed graphs, unique optimal solution exists.

---

### Strongly Connected Components & Graph Decomposition

#### SCC (Tarjan's/Kosaraju's)
**Real-World Uses:**
- **Compiler Optimization**: Call graph analysis - detecting mutually recursive functions
- **Web Crawling**: Google PageRank preprocessing - identifying tightly linked clusters
- **Recommendation Systems**: Finding communities with bidirectional influence
- **Deadlock Detection**: Operating systems - circular wait condition detection

**Why SCC?**: Linear time O(V+E), essential for graph condensation.

#### Articulation Points & Bridges
**Real-World Uses:**
- **Network Reliability**: Cisco - identifying critical routers/links (single points of failure)
- **Power Grid**: Identifying critical substations - ensuring redundancy
- **Social Network**: Finding key influencers - users whose removal fragments network
- **Road Networks**: Critical intersection detection - infrastructure planning

**Why Art. Points?**: Identifies vulnerability, essential for fault tolerance design.

#### Block-Cut Tree
**Real-World Uses:**
- **Network Design**: Hierarchical network topology - organizing biconnected components
- **Graph Analysis**: Research applications - studying graph structure properties
- **Fault-Tolerant Systems**: Designing resilient architectures

**Why Block-Cut?**: Represents biconnected structure, useful for resilience analysis.

---

### Tree Algorithms

#### LCA (Lowest Common Ancestor)
**Real-World Uses:**
- **File Systems**: Finding common parent directory - Unix/Linux path operations
- **Biology**: Phylogenetic tree analysis - finding common ancestors in evolution trees
- **Organizational Charts**: Finding common manager - corporate hierarchy queries
- **Version Control**: Git merge base - finding common commit ancestor

**Why LCA?**: O(1) query after O(N log N) preprocessing, extremely fast for repeated queries.

#### Heavy-Light Decomposition (HLD)
**Real-World Uses:**
- **Network Monitoring**: Tree network statistics - path queries on network topologies
- **Corporate Hierarchies**: Aggregate queries - sum of salaries in department paths
- **Game Development**: Skill tree optimizations - querying character progression paths

**Why HLD?**: O(log² N) path queries on trees, powerful for dynamic tree queries.

#### Centroid Decomposition
**Real-World Uses:**
- **Large-Scale Analytics**: Divide-and-conquer on tree data - processing hierarchical datasets
- **Network Analysis**: Finding central nodes - load balancing in tree networks
- **Research Applications**: Competitive programming problems - advanced tree queries

**Why Centroid?**: Reduces tree depth to O(log N), enables complex queries.

#### Link-Cut Tree
**Real-World Uses:**
- **Dynamic Networks**: Maintaining connectivity in changing networks - online graph updates
- **Research Systems**: Advanced graph algorithms - maintained by specialized libraries
- **Game Engines**: Managing dynamic scene graphs - when hierarchies change frequently

**Why Link-Cut?**: Handles edge additions/deletions in O(log N), most powerful dynamic tree structure.

---

### Advanced Graph Algorithms

#### Maximum Clique
**Real-World Uses:**
- **Social Network Analysis**: Finding tightly-knit communities - friend groups where everyone knows everyone
- **Bioinformatics**: Protein interaction networks - identifying functional modules
- **Fraud Detection**: Coordinated fake account detection - groups with suspicious mutual connections
- **Market Basket Analysis**: Products frequently bought together - retail recommendation systems

**Why Max Clique?**: NP-hard but essential for cohesive subgroup detection.

#### Graph Coloring (Chromatic Number)
**Real-World Uses:**
- **Exam Scheduling**: University timetabling - minimizing time slots for conflicting exams
- **Register Allocation**: Compiler optimization - assigning CPU registers to variables
- **Frequency Assignment**: Cellular networks - minimizing interference between towers
- **Map Coloring**: Cartography - ensuring adjacent regions have different colors
- **Sudoku Solvers**: Constraint programming - various puzzle applications

**Why Graph Coloring?**: Models conflict constraints elegantly, minimum colors = optimal resource count.

#### Steiner Tree
**Real-World Uses:**
- **VLSI Design**: Chip routing - connecting terminals with minimal wire length
- **Network Multicast**: Connecting multiple receivers - minimizing routing cost
- **Phylogenetic Trees**: Evolutionary biology - inferring ancestral relationships

**Why Steiner?**: Allows intermediate nodes, better than MST for subset connectivity.

#### Traveling Salesman (TSP approximations)
**Real-World Uses:**
- **Delivery Services**: FedEx, UPS route planning - visiting all stops efficiently
- **Manufacturing**: PCB drill routing - minimizing drill movement
- **DNA Sequencing**: Fragment assembly - ordering genetic sequences
- **Astronomy**: Telescope scheduling - observing all targets with minimal slew time

**Why TSP?**: NP-hard but practical approximations (2-opt, Christofides) work well.

#### Eulerian Path/Circuit
**Real-World Uses:**
- **DNA Sequencing**: De Bruijn graph traversal - assembling genome from reads
- **Route Planning**: Snow plow/street cleaning - covering all streets exactly once
- **Circuit Testing**: PCB testing - probe paths covering all connections
- **Chinese Postman**: Mail delivery - covering all edges with minimal repetition

**Why Eulerian?**: Polynomial time for edge coverage, natural for sequencing problems.

---

### Specialized Graph Algorithms

#### 2-SAT & 3-SAT
**Real-World Uses:**
- **Circuit Design**: Logic synthesis - satisfying boolean constraints
- **Automated Planning**: AI scheduling - finding feasible action sequences
- **Software Verification**: Constraint solving - checking program properties

**Why 2-SAT vs 3-SAT?**: 2-SAT is polynomial (SCC-based), 3-SAT is NP-complete.

#### Stable Marriage Problem
**Real-World Uses:**
- **Medical Residency Matching**: NRMP in US - matching med students to hospitals
- **School Choice**: Public school assignment - matching students to schools
- **Kidney Exchange**: Paired donation programs - matching donors to recipients

**Why Stable Marriage?**: Guaranteed stable solution, no blocking pairs, fair matching.

#### Chinese Postman Problem
**Real-World Uses:**
- **Garbage Collection**: Route optimization - covering all streets efficiently
- **Road Maintenance**: Inspection routes - ensuring all roads are checked
- **Postal Delivery**: Rural mail routes - covering delivery segments

**Why Chinese Postman?**: Extends Eulerian path for graphs requiring edge revisits.

#### Gomory-Hu Tree
**Real-World Uses:**
- **Network Reliability**: All-pairs min-cut - understanding network vulnerabilities
- **Image Segmentation**: Multi-label segmentation - partitioning images optimally
- **Research Applications**: Advanced flow problems - precomputing cut values

**Why Gomory-Hu?**: Compact representation of all min-cuts in O(n) flows.

---

## Data Structures

### Range Query Structures

#### Segment Tree
**Real-World Uses:**
- **MongoDB**: Range query optimization - efficiently querying ranges in databases
- **Google Analytics**: Time-series aggregation - sum/min/max over date ranges
- **Financial Systems**: Stock price queries - finding min/max in time windows
- **Competitive Games**: Leaderboard range queries - finding top players in rating ranges
- **Computational Geometry**: Rectangle queries - intersection and union operations

**Why Segment Tree?**: O(log N) updates and queries, extremely versatile with lazy propagation.

**Variants in Library:**
- **Segment Tree Beats**: Range max/min updates with chmin/chmax
- **Persistent Segment Tree**: Maintains all historical versions - version control
- **2D Segment Tree**: Rectangle queries - map range search applications
- **Lazy Propagation**: Efficient range updates - used in all modern applications

#### Fenwick Tree (Binary Indexed Tree - BIT)
**Real-World Uses:**
- **Gaming**: Live leaderboards - dynamic rank queries as scores update
- **Financial**: Cumulative stock volume - prefix sums in trading systems
- **E-commerce**: Inventory management - range sum queries for warehouse regions
- **Sports Analytics**: Player statistics - cumulative performance metrics

**Why Fenwick vs Segment Tree?**: Simpler code, less memory, faster constants, but less versatile.

**Variants:**
- **2D BIT**: Matrix range sums - image processing applications
- **Range Update Range Query BIT**: Lazy BIT for range operations

#### Sparse Table
**Real-World Uses:**
- **Database Systems**: RMQ preprocessing - static range minimum queries
- **LCA Preprocessing**: Constant-time queries - after initial O(N log N) build
- **Time Series**: Static min/max queries - historical data analysis

**Why Sparse Table?**: O(1) query time for static RMQ/GCD, unbeatable read performance.

#### SQRT Decomposition
**Real-World Uses:**
- **Teaching**: Easier to understand than segment trees - educational purposes
- **Simple Range Queries**: When segment tree is overkill - prototyping systems
- **Mo's Algorithm**: Query optimization - offline range queries

**Why SQRT?**: Trade-off between simplicity and performance, good for learning.

---

### Advanced Tree Structures

#### Treap (Randomized BST)
**Real-World Uses:**
- **Balanced BST Alternative**: When AVL/Red-Black is too complex
- **Randomized Algorithms**: Where probabilistic guarantees suffice
- **Persistent Treap**: Functional programming data structures - maintaining history

**Why Treap?**: Simpler than AVL/RB trees, good average-case performance.

#### Implicit Treap
**Real-World Uses:**
- **Text Editors**: Rope data structure - efficient string operations (insert, delete, split, merge)
- **Sublime Text/VSCode**: Large file handling - managing document buffers
- **Undo/Redo Systems**: Version tracking - maintaining operation history
- **Array Operations**: Range reverse, cut, paste - advanced array manipulation

**Why Implicit Treap?**: O(log N) for cut/merge/reverse, essential for text editor backends.

---

### Union-Find (Disjoint Set Union - DSU)

#### Standard DSU
**Real-World Uses:**
- **Image Processing**: Photoshop flood fill - connected component labeling
- **Kruskal's MST**: Essential component - checking cycle formation
- **Network Connectivity**: Dynamic connectivity - checking if nodes are connected
- **Social Networks**: Friend groups - merging communities

**Why DSU?**: Nearly O(1) amortized operations, inverse Ackermann function.

**Variants:**
- **DSU with Rollbacks**: Undo operations - used in parallel algorithms
- **Persistent DSU**: Version history - maintaining past states
- **Augmented DSU**: Additional info per component - sizes, sums, etc.

---

### String Data Structures

#### Trie (Prefix Tree)
**Real-World Uses:**
- **Google Search**: Autocomplete suggestions - instant prefix matching
- **IDE Code Completion**: IntelliJ, VSCode - suggesting variable names
- **IP Routing**: Router forwarding tables - longest prefix matching
- **Spell Checkers**: Dictionary lookups - fast prefix searches
- **DNS Systems**: Domain name resolution - hierarchical name lookup

**Why Trie?**: O(L) lookup where L = string length, perfect for prefix queries.

**Variants:**
- **Persistent Trie**: Version control - XOR basis problems, historical queries

#### Suffix Array & Suffix Tree
**Real-World Uses:**
- **Genome Sequencing**: BLAST, DNA analysis - finding all occurrences of patterns
- **Data Compression**: gzip, bzip2 - finding repeated substrings
- **Plagiarism Detection**: Turnitin - longest common substring detection
- **Text Processing**: Full-text search engines - substring search

**Why Suffix Structures?**: All substring queries answerable, powerful but memory-intensive.

#### Aho-Corasick Automaton
**Real-World Uses:**
- **Antivirus Software**: Norton, McAfee - scanning for multiple virus signatures simultaneously
- **Content Filtering**: Firewall keyword blocking - detecting banned words
- **Bioinformatics**: Multiple pattern matching - searching for gene sequences
- **Log Analysis**: Security monitoring - detecting multiple attack patterns

**Why Aho-Corasick?**: O(N + M + Z) for multiple pattern matching, Z = total matches.

---

### Persistent Data Structures

#### Persistent Segment Tree
**Real-World Uses:**
- **Git/Version Control**: Historical queries - accessing past states
- **Blockchain**: Versioned state - maintaining history immutably
- **Undo Systems**: Multi-level undo - maintaining all versions efficiently
- **Time-travel Debugging**: GDB time-travel - querying past program states

**Why Persistent Segment Tree?**: O(log N) time and space per version, powerful versioning.

#### Persistent Treap
**Real-World Uses:**
- **Functional Programming**: Haskell, Clojure persistent collections
- **Concurrent Systems**: Lock-free data structures - multiple readers simultaneously
- **Historical Databases**: Temporal databases - querying data as of any time

**Why Persistent Treap?**: Immutable updates, safe concurrency, functional paradigm.

---

### Specialized Structures

#### Mo's Algorithm
**Real-World Uses:**
- **Query Optimization**: Offline range query processing - reordering for cache efficiency
- **Analytics Systems**: OLAP cube queries - optimizing query execution order
- **Research**: Competitive programming - when online queries are too expensive

**Why Mo's?**: Reduces online O(N²) to offline O(N√N), query reordering is key.

---

## Dynamic Programming Optimizations

### Convex Hull Trick (CHT)
**Real-World Uses:**
- **Economic Modeling**: Production cost optimization - choosing between linear cost functions
- **Resource Allocation**: Cloud computing cost minimization - selecting pricing tiers
- **Machine Learning**: Piecewise linear approximations - model compression
- **Finance**: Optimal portfolio rebalancing - minimizing transaction costs

**Why CHT?**: Reduces DP from O(N²) to O(N log N) or O(N) for monotonic slopes.

**Variants:**
- **Dynamic CHT**: Non-monotonic insertions - more flexible but slower
- **Li Chao Tree**: Persistent line queries - segment-based optimization

### Divide & Conquer Optimization
**Real-World Uses:**
- **Matrix Chain Multiplication**: Compiler optimization - optimal parenthesization
- **Warehouse Location**: Facility placement - minimizing distribution costs
- **Dynamic Programming**: Various DP problems satisfying quadrangle inequality

**Why D&C Opt?**: Reduces O(N²K) to O(NK log N) when transition has optimal substructure.

### Knuth Optimization
**Real-World Uses:**
- **Optimal BST Construction**: Database indexing - building BST with access frequencies
- **Paragraph Formatting**: TeX typesetting - optimal line breaking
- **File Merging**: Huffman-like problems - optimal merge order

**Why Knuth?**: Reduces O(N³) to O(N²) exploiting monotonicity of optimal split points.

### SOS DP (Sum over Subsets)
**Real-World Uses:**
- **Feature Selection**: Machine learning - aggregating over feature combinations
- **Game Theory**: Solving games on bitmasks - Nim-like games
- **Subset Enumeration**: E-commerce recommendation - considering product combinations

**Why SOS DP?**: Reduces O(3ⁿ) to O(n·2ⁿ), essential for bitmask DP problems.

### Digit DP
**Real-World Uses:**
- **Number Theory**: Counting numbers with properties - digits sum to X
- **Analytics**: Range counting queries - how many numbers in range have property P
- **Constraint Programming**: Generating valid numbers - satisfying digit constraints

**Why Digit DP?**: Handles large ranges (10¹⁸), position-based constraints.

---

## Math & Linear Algebra

### Fast Fourier Transform (FFT) & Number Theoretic Transform (NTT)
**Real-World Uses:**
- **Spotify/Audio Processing**: Audio effects, equalizers - frequency domain transformation
- **Image Processing**: JPEG compression - 2D DCT (related to FFT)
- **Signal Analysis**: Telecommunications - modulation/demodulation
- **Polynomial Multiplication**: Computer algebra systems (Mathematica, Maple)
- **Convolution**: Deep learning (CNNs) - though specialized hardware used

**Why FFT?**: Reduces O(N²) polynomial multiplication to O(N log N).
**Why NTT?**: Exact arithmetic modulo prime, avoids floating-point errors.

**Variants:**
- **2D FFT**: Image processing
- **Online NTT**: Incremental polynomial multiplication
- **FWHT**: Boolean convolutions - XOR/AND/OR convolutions

### Matrix Operations

#### Gaussian Elimination
**Real-World Uses:**
- **Machine Learning**: Linear regression - solving normal equations
- **Circuit Analysis**: SPICE simulation - solving Kirchhoff's equations
- **3D Graphics**: OpenGL transformations - inverting matrices
- **Physics Simulations**: Finite element analysis - solving linear systems
- **Economics**: Input-output models - Leontief economic analysis

**Why Gaussian?**: O(N³) but highly optimized, numerically stable variants exist.

**Variants:**
- **Modular Gaussian**: Exact arithmetic - XOR basis problems
- **Modulo 2 Gaussian**: Binary linear algebra - coding theory

#### Matrix Exponentiation
**Real-World Uses:**
- **Graph Algorithms**: Counting paths - number of walks of length K
- **Markov Chains**: Long-term probability - PageRank computation
- **Recurrence Relations**: Fibonacci, linear recurrences - fast computation
- **Dynamic Programming**: Optimizing DP with matrix - tiling problems

**Why Matrix Exp?**: Reduces O(N) to O(log N) for linear recurrences.

#### Determinant Computation
**Real-World Uses:**
- **Linear Algebra**: Invertibility checking - system solvability
- **Combinatorics**: Counting spanning trees (Kirchhoff) - graph enumeration
- **Cryptography**: Lattice-based crypto - checking linear independence

**Why Determinant?**: Fundamental linear algebra operation, O(N³) via Gaussian.

**Variants:**
- **Sparse Matrix Determinant**: Large sparse matrices - network analysis
- **Modular Determinant**: Exact computation - number theory applications

### Linear Programming

#### Simplex Algorithm
**Real-World Uses:**
- **Airlines**: Crew scheduling, flight planning - maximizing profit under constraints
- **Manufacturing**: Production optimization - resource allocation
- **Finance**: Portfolio optimization - Markowitz model
- **Logistics**: Transportation problem - minimizing shipping costs
- **Agriculture**: Crop planning - maximizing yield with land/water constraints

**Why Simplex?**: Exponential worst-case but excellent average-case, very practical.

---

### Special Functions & Sequences

#### Berlekamp-Massey Algorithm
**Real-World Uses:**
- **Coding Theory**: Error-correcting codes - finding linear feedback shift registers
- **Sequence Prediction**: Finding hidden recurrence - time series analysis
- **Cryptanalysis**: Stream cipher analysis - breaking weak LFSRs

**Why Berlekamp-Massey?**: Finds shortest linear recurrence for sequence in O(N²).

#### Lagrange Interpolation
**Real-World Uses:**
- **Secret Sharing**: Shamir's scheme - distributing cryptographic secrets
- **Data Recovery**: Interpolating missing data - assuming polynomial model
- **Computer Graphics**: Bezier curves - smooth curve fitting
- **Numerical Analysis**: Function approximation - polynomial fitting

**Why Lagrange?**: Finds unique polynomial through N points in O(N²).

---

## String Algorithms

### Pattern Matching

#### KMP (Knuth-Morris-Pratt)
**Real-World Uses:**
- **Text Editors**: Find function - efficient substring search
- **DNA Analysis**: Gene sequence matching - finding specific genetic markers
- **Plagiarism Detection**: Document comparison - finding copied passages
- **Network Security**: Deep packet inspection - detecting patterns in traffic

**Why KMP?**: O(N + M) guaranteed, no backtracking, failure function preprocessing.

#### Z-Algorithm
**Real-World Uses:**
- **String Matching**: Alternative to KMP - finding all pattern occurrences
- **Competitive Programming**: Simpler to implement than KMP
- **Text Processing**: Various string problems - leveraging Z-array structure

**Why Z-Algorithm?**: Simpler than KMP, also O(N + M), computes Z-array elegantly.

### Advanced String Structures

#### String Hashing
**Real-World Uses:**
- **Duplicate Detection**: Google Search - finding duplicate web pages
- **Rabin-Karp**: Multiple pattern matching - spam filtering
- **Cache Systems**: CDN cache keys - efficient string comparison
- **Plagiarism Detection**: Fast substring comparison - initial filtering

**Why Hashing?**: O(1) string comparison after O(N) preprocessing, probabilistic but practical.

**Variants:**
- **2D Hashing**: Image similarity - detecting similar image patches
- **Dynamic Hashing**: With updates - maintaining hash under modifications

#### Manacher's Algorithm
**Real-World Uses:**
- **Palindrome Detection**: Finding longest palindromic substring - text analysis
- **DNA Sequencing**: Detecting palindromic sequences - genetic analysis
- **Competitive Programming**: Palindrome problems - O(N) solution

**Why Manacher's?**: O(N) for all longest palindromes, better than O(N²).

#### Palindromic Tree (Eertree)
**Real-World Uses:**
- **Advanced String Problems**: Counting distinct palindromes - research applications
- **Competitive Programming**: Sophisticated palindrome queries
- **Text Analysis**: Palindrome statistics - linguistic analysis

**Why Palindromic Tree?**: Linear time construction, supports various palindrome queries.

---

## Number Theory

### Primality & Factorization

#### Miller-Rabin Primality Test
**Real-World Uses:**
- **RSA Cryptography**: Generating large primes - SSL/TLS key generation
- **Blockchain**: Cryptocurrency mining - proof-of-work validation
- **Cryptographic Protocols**: Diffie-Hellman, ElGamal - prime selection
- **Security**: Random prime generation - various cryptosystems

**Why Miller-Rabin?**: Probabilistic O(k log³ N), certain for specific bases, practical for large numbers.

#### Pollard's Rho Algorithm
**Real-World Uses:**
- **Cryptanalysis**: Breaking weak RSA keys - factoring challenge numbers
- **Research**: Integer factorization - mathematical research
- **Security Testing**: Analyzing key strength - penetration testing

**Why Pollard's Rho?**: Heuristic O(N^(1/4)), much faster than trial division for large composites.

#### Sieve Algorithms
**Real-World Uses:**
- **Cryptography**: Prime generation - creating prime pools
- **Number Theory**: Research applications - studying prime distributions
- **Competitive Programming**: Fast prime generation - preprocessing

**Why Different Sieves?**
- **Eratosthenes**: Simple, O(N log log N) - small ranges
- **Linear Sieve**: O(N), computes multiplicative functions - advanced uses
- **Segmented Sieve**: Large ranges - memory-efficient
- **Min_25 Sieve**: Prime counting - high-performance modern technique

---

### Modular Arithmetic

#### Extended Euclidean Algorithm
**Real-World Uses:**
- **RSA Cryptography**: Computing modular inverses - private key generation
- **Diophantine Equations**: Finding integer solutions - number theory problems
- **Bezout's Identity**: Certificate generation - cryptographic proofs

**Why Extended Euclid?**: O(log N), finds GCD and Bezout coefficients simultaneously.

#### Chinese Remainder Theorem (CRT)
**Real-World Uses:**
- **RSA Cryptography**: Faster decryption - using Chinese Remainder for modular exponentiation
- **Calendar Calculations**: Synchronizing cycles - Easter date computation
- **Distributed Computing**: Range splitting - parallel computation with different moduli
- **Error Correction**: Combining redundant representations - residue number systems

**Why CRT?**: Solves system of congruences, enables fast modular arithmetic.

#### Discrete Logarithm & Root
**Real-World Uses:**
- **Cryptanalysis**: Breaking Diffie-Hellman - security analysis
- **Number Theory**: Solving congruences - research applications
- **Elliptic Curve Crypto**: Point operations - advanced cryptography

**Why Discrete Log?**: Baby-step giant-step O(√p), essential for cryptanalysis.

---

### Diophantine Equations & Linear Congruences

#### Linear Diophantine Equations
**Real-World Uses:**
- **Currency Problems**: Making exact change - coin combination problems
- **Resource Allocation**: Integer constraints - operations research
- **Number Theory**: Classic problems - mathematical puzzles

**Why Diophantine?**: Finds all integer solutions, GCD condition for solvability.

---

### Combinatorics

#### Lucas' Theorem
**Real-World Uses:**
- **Combinatorics**: Computing binomial coefficients modulo prime - when N, K are huge
- **Competitive Programming**: Fast nCr mod p - efficient computation
- **Coding Theory**: Designing error-correcting codes - combinatorial structures

**Why Lucas?**: Reduces nCr mod p to products of smaller binomials, very fast.

#### Bell Numbers & Stirling Numbers
**Real-World Uses:**
- **Combinatorics**: Partition counting - set theory problems
- **Statistics**: Distribution theory - moments of random variables
- **Research**: Enumeration problems - mathematical research

**Why Stirling Numbers?**: Count various combinatorial structures (partitions, surjections).

---

## Geometry, Game Theory & Miscellaneous

### Computational Geometry

#### Convex Hull
**Real-World Uses:**
- **Computer Graphics**: Rendering optimization - collision detection, visibility
- **Robotics**: Path planning - safe navigation zones
- **GIS Systems**: Geographic analysis - boundary detection
- **Image Processing**: Shape analysis - object detection

**Why Convex Hull?**: O(N log N) optimal, fundamental geometric operation.

#### Line Intersection & Segment Queries
**Real-World Uses:**
- **CAD Systems**: AutoCAD - design validation
- **Computer Graphics**: Ray tracing - rendering engines
- **Robotics**: Collision detection - motion planning
- **GIS**: Map overlay - geographic analysis

**Why Geometry Algorithms?**: Essential for spatial reasoning, well-studied classical algorithms.

---

### Game Theory

#### Nim & Grundy Numbers
**Real-World Uses:**
- **Game Development**: Optimal AI for games - making perfect moves
- **Competitive Programming**: Game theory problems - impartial game analysis
- **Research**: Combinatorial game theory - mathematical studies

**Why Game Theory?**: XOR-based Nim theorem, general Sprague-Grundy for impartial games.

---

### Miscellaneous Techniques

#### Meet-in-the-Middle
**Real-World Uses:**
- **Cryptanalysis**: Breaking block ciphers - reducing search space from 2ⁿ to 2^(n/2)
- **Subset Sum**: Faster subset sum - reducing exponential complexity
- **Competitive Programming**: Breaking O(2ⁿ) to O(2^(n/2)) - various problems

**Why Meet-in-the-Middle?**: Space-time tradeoff, square-root speedup.

---

## Summary

This library contains battle-tested implementations of algorithms powering:
- **Search Engines**: Google (PageRank, Suffix Arrays, Tries)
- **Social Networks**: Facebook, LinkedIn (Graph algorithms, BFS, Matching)
- **E-commerce**: Amazon (Max Flow, DP, Assignment Problems)
- **Streaming**: Netflix, Spotify (MCMF, FFT, Graphs)
- **Transportation**: Uber, Lyft (Matching, Shortest Paths)
- **Finance**: Trading systems (DP, Linear Programming)
- **Security**: Cryptography (Number Theory, Primality, Modular Arithmetic)
- **Operating Systems**: Schedulers, File Systems (Graph algorithms, Trees)

Each algorithm is chosen for specific reasons - understand **why** it's used, not just **how** it works!
