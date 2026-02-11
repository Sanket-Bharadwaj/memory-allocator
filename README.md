# Memory Allocator — From Scratch

A low-level systems project focused on understanding how memory actually works beneath `malloc`.

This is not a framework project.  
This is not tutorial-driven code.

The goal is to build allocator logic step-by-step and develop real machine-level intuition.

---

## 🎯 Objective

Build a memory allocator from first principles to deeply understand:

- Memory layout  
- Heap mechanics  
- Pointer arithmetic  
- Alignment  
- Allocation strategies  
- Fragmentation  
- Metadata design  
- Systems tradeoffs  

Most developers use memory without understanding it.

This project removes that abstraction.

---

## ✅ Current Implementation

**Stage: Foundation (Bump Allocator)**

Features:

- Static 10MB heap
- Linear allocation
- 8-byte alignment
- Boundary protection (prevents overflow)
- Zero external dependencies

Allocation is currently performed by moving a pointer forward inside a reserved memory region.

Extremely fast.  
Extremely simple.  
Intentionally limited.

---

## 🧠 How It Works

A fixed block of memory is reserved:

```
|--------------------------------|
heap_start                 heap_end
```

A pointer tracks the next free location.

### Allocation Flow:

1. Align requested size to 8 bytes  
2. Ensure heap capacity is not exceeded  
3. Return current pointer  
4. Move pointer forward  

Core idea:

> **Allocation = pointer movement**

---

## ⚠️ Known Limitation (By Design)

This allocator **does NOT support `free()` yet.**

Meaning:

- Memory is never reused  
- Heap will eventually exhaust  
- Not suitable for long-running programs  

This is intentional — complexity will be introduced gradually.

Understanding fundamentals first is critical in systems engineering.

---

## 🚀 Build & Run

```bash
clang src/allocator.c -o allocator
./allocator
```

---

## 🛣️ Roadmap

### Phase 1 — Foundation ✅
- Static heap  
- Bump allocator  

### Phase 2 — Memory Reuse
- Block metadata  
- Implement `free()`  
- Free list  

### Phase 3 — Smarter Allocation
- First-fit / best-fit strategies  
- Block splitting  
- Fragmentation handling  

### Phase 4 — Toward Real Allocators
- Block coalescing  
- Reduce allocator overhead  
- Possible `mmap` usage  
- Compare against libc malloc  

---

## 🧭 Philosophy

This is a **depth-first** project.

Not built to finish quickly.  
Built to understand deeply.

After this project, memory stops being mysterious —  
and starts becoming mechanical.

That is the turning point for every serious systems engineer.
