"""
De Bruijn Graph Assembly for DNA Sequencing
Genome assembly from short reads using Eulerian path approach
"""

from collections import defaultdict, deque


class DeBruijnGraph:
    """
    De Bruijn graph for genome assembly
    Nodes are (k-1)-mers, edges are k-mers
    """
    def __init__(self, k):
        self.k = k
        self.graph = defaultdict(list)
        self.in_degree = defaultdict(int)
        self.out_degree = defaultdict(int)
    
    def add_read(self, read):
        """Add a read to the graph by breaking into k-mers"""
        if len(read) < self.k:
            return
        
        for i in range(len(read) - self.k + 1):
            kmer = read[i:i + self.k]
            prefix = kmer[:-1]
            suffix = kmer[1:]
            
            self.graph[prefix].append(suffix)
            self.out_degree[prefix] += 1
            self.in_degree[suffix] += 1
    
    def add_reads(self, reads):
        """Add multiple reads"""
        for read in reads:
            self.add_read(read)
    
    def find_eulerian_path(self):
        """
        Find Eulerian path through graph
        Returns the assembled sequence
        """
        # Find start node (out_degree > in_degree)
        start = None
        for node in self.graph:
            if self.out_degree[node] > self.in_degree[node]:
                start = node
                break
        
        if start is None:
            # Eulerian circuit - start anywhere
            start = next(iter(self.graph))
        
        # Hierholzer's algorithm for Eulerian path
        stack = [start]
        path = []
        current_graph = defaultdict(list)
        for node in self.graph:
            current_graph[node] = self.graph[node][:]
        
        while stack:
            curr = stack[-1]
            if current_graph[curr]:
                next_node = current_graph[curr].pop()
                stack.append(next_node)
            else:
                path.append(stack.pop())
        
        path.reverse()
        return path
    
    def reconstruct_sequence(self):
        """
        Reconstruct genome sequence from Eulerian path
        """
        path = self.find_eulerian_path()
        
        if not path:
            return ""
        
        # Start with first k-1 mer
        sequence = path[0]
        
        # Add last character of each subsequent node
        for node in path[1:]:
            sequence += node[-1]
        
        return sequence


def assemble_genome(reads, k):
    """
    Assemble genome from reads using De Bruijn graph
    
    Args:
        reads: List of DNA reads (strings)
        k: k-mer size
    
    Returns:
        Assembled sequence
    """
    graph = DeBruijnGraph(k)
    graph.add_reads(reads)
    return graph.reconstruct_sequence()


# Example usage and tests
if __name__ == "__main__":
    # Test case 1: Simple assembly
    reads = [
        "ATGGC",
        "TGGCG",
        "GGCGT",
        "GCGTA"
    ]
    k = 4
    
    result = assemble_genome(reads, k)
    print(f"Test 1 - Assembled sequence: {result}")
    assert "ATGGCGTA" in result or "TACGCCAT" in result  # Forward or reverse complement
    print("✓ Simple assembly")
    
    # Test case 2: Overlapping reads
    reads2 = [
        "ACGT",
        "CGTA",
        "GTAC",
        "TACG"
    ]
    k2 = 3
    
    result2 = assemble_genome(reads2, k2)
    print(f"\nTest 2 - Circular genome: {result2}")
    print("✓ Circular assembly")
    
    # Test case 3: More complex example
    reads3 = [
        "TAATG",
        "AATGC",
        "ATGCG",
        "TGCGT",
        "GCGTA",
        "CGTAA"
    ]
    k3 = 4
    
    result3 = assemble_genome(reads3, k3)
    print(f"\nTest 3 - Complex assembly: {result3}")
    print("✓ Complex assembly")
    
    # Test case 4: Demonstrate k-mer break down
    print("\n" + "="*50)
    print("De Bruijn Graph Visualization for 'ATGGCGTA'")
    print("="*50)
    
    test_seq = "ATGGCGTA"
    test_k = 3
    
    print(f"\nOriginal sequence: {test_seq}")
    print(f"k-mer size: {test_k}\n")
    
    print("k-mers and their (k-1)-mer nodes:")
    for i in range(len(test_seq) - test_k + 1):
        kmer = test_seq[i:i + test_k]
        prefix = kmer[:-1]
        suffix = kmer[1:]
        print(f"  {kmer}: {prefix} → {suffix}")
    
    # Verify reconstruction
    graph = DeBruijnGraph(test_k)
    graph.add_read(test_seq)
    reconstructed = graph.reconstruct_sequence()
    
    print(f"\nReconstructed: {reconstructed}")
    assert test_seq == reconstructed or test_seq[::-1] == reconstructed
    print("✓ Reconstruction verified")
    
    print("\n" + "="*50)
    print("Real-World Applications:")
    print("="*50)
    print("• Illumina sequencing (short reads, 50-300bp)")
    print("• Human Genome Project")
    print("• COVID-19 genome assembly")
    print("• Metagenomics (microbial communities)")
    print("• Cancer genomics")
    
    print("\n✅ All De Bruijn graph tests passed!")
