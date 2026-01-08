/*
 * Unprecedented Algorithm: Neural Program Synthesis
 * Category: AI / Compilers
 */

// ==========================================
// INTUITION & IMAGINATION
// ==========================================
// Problem: Can computers write their own code?
// Input: Input/Output examples (e.g., [1,2] -> 3, [2,3] -> 5).
// Output: A program (e.g., "func(a,b) { return a + b; }").
//
// Imagination:
// Imagine the space of ALL possible programs. It is an infinitely large library.
// Most books in this library are gibberish ("if x { print }").
// Some are valid but wrong.
// Only one tiny book is the correct program.
//
// Brute Force is impossible (Combatorial Explosion).
// Directed Search (Beam Search) is needed.
// We treat code generation as a game or a tree search.
// - Root: Empty program.
// - Branches: "Add +", "Add 1", "Add Var".
// - Heuristic: "How close is current output to target?"
//
// We combine Symbolic Execution (running exact logic) with Neural Heuristics (guessing "I need a loop here").

// ==========================================
// REAL WORLD APPLICATIONS
// ==========================================
// 1. Excel FlashFill: Auto-completing string patterns based on one example.
// 2. Automated Bug Fixes: Finding patches for crash reports.
// 3. Super-Optimizers: Finding the absolute fastest assembly sequence for a math kernel.

#[derive(Clone, Debug, PartialEq)]
enum Op {
    Plus,
    Minus,
    Mult,
    Var(usize), // index of input variable
    Const(i32),
}

#[derive(Clone, Debug)]
struct Program {
    ops: Vec<Op>,
    // Stack-based DSL. RPN.
}

impl Program {
    fn evaluate(&self, inputs: &[i32]) -> Option<i32> {
        let mut stack = Vec::new();
        for op in &self.ops {
            match op {
                Op::Const(val) => stack.push(*val),
                Op::Var(idx) => {
                    if *idx >= inputs.len() { return None; }
                    stack.push(inputs[*idx]);
                }
                Op::Plus => {
                    if stack.len() < 2 { return None; }
                    let b = stack.pop()?;
                    let a = stack.pop()?;
                    stack.push(a + b);
                }
                Op::Minus => {
                    if stack.len() < 2 { return None; }
                    let b = stack.pop()?;
                    let a = stack.pop()?;
                    stack.push(a - b);
                }
                Op::Mult => {
                    if stack.len() < 2 { return None; }
                    let b = stack.pop()?;
                    let a = stack.pop()?;
                    stack.push(a * b);
                }
            }
        }
        stack.pop()
    }
}

// Simple Bottom-Up Enumeration Search
// (Actual Neural Synthesis replaces this enumeration with a probabilistic model P(program | input, output))
pub fn synthesize(examples: &[ (Vec<i32>, i32) ]) -> Option<Program> {
    // Breadth-First Search over program space
    let mut queue = std::collections::VecDeque::new();
    
    // Start with atoms
    // Assuming 2 vars
    queue.push_back(Program { ops: vec![Op::Var(0)] });
    queue.push_back(Program { ops: vec![Op::Var(1)] });
    queue.push_back(Program { ops: vec![Op::Const(1)] });
    
    let max_ops = 5;
    
    let mut visited_signatures = std::collections::HashSet::new();
    
    let mut steps = 0;
    while let Some(prog) = queue.pop_front() {
        steps += 1;
        if steps > 5000 { break; }
        
        // Check correctness
        let mut correct = true;
        let mut signature = Vec::new(); // Outputs on examples
        
        for (input, target) in examples {
            if let Some(res) = prog.evaluate(input) {
                signature.push(res);
                if res != *target {
                    correct = false;
                }
            } else {
                correct = false;
                signature.push(-999999); // Error
                break;
            }
        }
        
        if correct && signature.len() == examples.len() {
            println!("Solution found after {} steps!", steps);
            return Some(prog);
        }
        
        // Pruning: Don't explore semantically equivalent programs
        if visited_signatures.contains(&signature) {
            continue;
        }
        visited_signatures.insert(signature);
        
        if prog.ops.len() >= max_ops { continue; }
        
        // Expand: Add operations
        // 1. Add binary op
        for op in vec![Op::Plus, Op::Minus, Op::Mult] {
            let mut new_ops = prog.ops.clone();
            new_ops.push(op);
            queue.push_back(Program { ops: new_ops });
        }
        
        // 2. Add operand (push onto stack)
        // Usually, in RPN, we push operands then operators.
        // If stack depth is low, we need operands.
        // Heuristic: only add operands if we intend to reduce later.
        for op in vec![Op::Var(0), Op::Var(1), Op::Const(1)] {
             let mut new_ops = prog.ops.clone();
             new_ops.push(op);
             queue.push_back(Program { ops: new_ops });
        }
    }
    
    None
}

fn main() {
    // Task: Learn "2*a + b"
    let examples = vec![
        (vec![2, 3], 7),   // 2*2 + 3 = 7
        (vec![5, 1], 11),  // 2*5 + 1 = 11
        (vec![0, 4], 4),   // 2*0 + 4 = 4
    ];
    
    if let Some(p) = synthesize(&examples) {
        println!("Synthesized: {:?}", p);
        // Expected: Var(0), Const(2) or Var(0), Mult, Var(1), Plus... (RPN)
        // Or Var(0), Var(0), Plus, Var(1), Plus
    } else {
        println!("Failed to synthesize.");
    }
}
