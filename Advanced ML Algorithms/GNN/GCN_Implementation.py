"""
Graph Convolutional Network (GCN) Implementation
PyTorch implementation for node classification
Based on: Kipf & Welling (2017)
"""

import torch
import torch.nn as nn
import torch.nn.functional as F
import numpy as np


class GCNLayer(nn.Module):
    """
    Single Graph Convolutional Layer
    H^(l+1) = σ(D^(-1/2) A D^(-1/2) H^(l) W^(l))
    """
    def __init__(self, in_features, out_features, use_bias=True):
        super(GCNLayer, self).__init__()
        self.in_features = in_features
        self.out_features = out_features
        
        # Weight matrix
        self.weight = nn.Parameter(torch.FloatTensor(in_features, out_features))
        
        # Bias
        if use_bias:
            self.bias = nn.Parameter(torch.FloatTensor(out_features))
        else:
            self.register_parameter('bias', None)
        
        self.reset_parameters()
    
    def reset_parameters(self):
        """Initialize weights using Xavier initialization"""
        nn.init.xavier_uniform_(self.weight)
        if self.bias is not None:
            nn.init.zeros_(self.bias)
    
    def forward(self, x, adj):
        """
        Forward pass
        Args:
            x: Node features (N x in_features)
            adj: Normalized adjacency matrix (N x N)
        Returns:
            output: Updated node features (N x out_features)
        """
        # Linear transformation: XW
        support = torch.mm(x, self.weight)
        
        # Graph convolution: A * XW
        output = torch.spmm(adj, support)
        
        # Add bias
        if self.bias is not None:
            output = output + self.bias
        
        return output


class GCN(nn.Module):
    """
    2-Layer Graph Convolutional Network
    For node classification tasks
    """
    def __init__(self, n_features, n_hidden, n_classes, dropout=0.5):
        super(GCN, self).__init__()
        
        self.gc1 = GCNLayer(n_features, n_hidden)
        self.gc2 = GCNLayer(n_hidden, n_classes)
        self.dropout = dropout
    
    def forward(self, x, adj):
        """
        Forward pass through GCN
        Args:
            x: Node features (N x n_features)
            adj: Normalized adjacency matrix (N x N)
        Returns:
            output: Class probabilities (N x n_classes)
        """
        # First GCN layer + ReLU + Dropout
        x = F.relu(self.gc1(x, adj))
        x = F.dropout(x, self.dropout, training=self.training)
        
        # Second GCN layer
        x = self.gc2(x, adj)
        
        # Log softmax for classification
        return F.log_softmax(x, dim=1)


def normalize_adjacency(adj):
    """
    Normalize adjacency matrix: D^(-1/2) A D^(-1/2)
    Adds self-loops: A' = A + I
    """
    # Add self-loops
    adj = adj + torch.eye(adj.size(0))
    
    # Compute degree matrix
    degree = torch.sum(adj, dim=1)
    
    # D^(-1/2)
    d_inv_sqrt = torch.pow(degree, -0.5)
    d_inv_sqrt[torch.isinf(d_inv_sqrt)] = 0.
    d_mat_inv_sqrt = torch.diag(d_inv_sqrt)
    
    # D^(-1/2) A D^(-1/2)
    adj_normalized = torch.mm(torch.mm(d_mat_inv_sqrt, adj), d_mat_inv_sqrt)
    
    return adj_normalized


def sparse_mx_to_torch_sparse_tensor(sparse_mx):
    """Convert scipy sparse matrix to PyTorch sparse tensor"""
    import scipy.sparse as sp
    
    sparse_mx = sparse_mx.tocoo().astype(np.float32)
    indices = torch.from_numpy(
        np.vstack((sparse_mx.row, sparse_mx.col)).astype(np.int64))
    values = torch.from_numpy(sparse_mx.data)
    shape = torch.Size(sparse_mx.shape)
    return torch.sparse.FloatTensor(indices, values, shape)


# Example usage
if __name__ == "__main__":
    # Create synthetic graph data
    n_nodes = 100
    n_features = 16
    n_classes = 3
    n_hidden = 32
    
    # Random node features
    features = torch.randn(n_nodes, n_features)
    
    # Random adjacency matrix (sparse)
    adj = torch.rand(n_nodes, n_nodes)
    adj = (adj > 0.9).float()  # Sparse graph
    adj = (adj + adj.t()) / 2  # Make symmetric
    
    # Normalize adjacency
    adj_norm = normalize_adjacency(adj)
    
    # Random labels
    labels = torch.randint(0, n_classes, (n_nodes,))
    
    # Create model
    model = GCN(n_features=n_features, 
                n_hidden=n_hidden, 
                n_classes=n_classes,
                dropout=0.5)
    
    # Forward pass
    model.eval()
    with torch.no_grad():
        output = model(features, adj_norm)
    
    print(f"✓ GCN Model Created")
    print(f"  Input shape: {features.shape}")
    print(f"  Output shape: {output.shape}")
    print(f"  Number of parameters: {sum(p.numel() for p in model.parameters())}")
    
    # Check output is valid log probabilities
    assert output.shape == (n_nodes, n_classes)
    assert torch.allclose(torch.exp(output).sum(dim=1), torch.ones(n_nodes), atol=1e-5)
    
    print("\n✅ GCN implementation verified!")
