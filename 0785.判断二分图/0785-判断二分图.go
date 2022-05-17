const UNCOLORED int = 0
const RED int = 1
const GREEN int = 2

func isBipartite(graph [][]int) bool {
    n := len(graph)
    color := make([]int, n)

    for i,_ := range graph {
        if color[i] == UNCOLORED {
            if !dfs( graph, color, i, RED ) {
                return false
            } 
        }
    }

    return true
}

func dfs(graph [][]int, color []int, index int, selfColor int) bool {
    color[index] = selfColor
    neighborColor := RED 
    if selfColor == RED {
        neighborColor = GREEN
    }
    
    for _, neighbor := range graph[index] {
        if color[neighbor] == UNCOLORED {
            if !dfs(graph, color, neighbor, neighborColor) {
                return false
            }
        } else if color[neighbor] != neighborColor {
            return false
        }
    }

    return true
}