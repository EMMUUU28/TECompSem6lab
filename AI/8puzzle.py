import heapq

class PuzzleNode:
    def __init__(self, state, parent=None, move="Initial"):
        self.state = state
        self.parent = parent
        self.move = move
        self.depth = 0
        if parent:
            self.depth = parent.depth + 1

    def __lt__(self, other):
        return self.depth < other.depth

    def __eq__(self, other):
        return self.state == other.state

    def __hash__(self):
        return hash(str(self.state))

    def __str__(self):
        return str(self.state)

    def get_blank_position(self):
        for i, row in enumerate(self.state):
            if 0 in row:
                return (i, row.index(0))

    def expand(self):
        blank_pos = self.get_blank_position()
        children = []
        moves = [(0, 1), (0, -1), (1, 0), (-1, 0)]  # right, left, down, up

        for move in moves:
            new_row, new_col = blank_pos[0] + move[0], blank_pos[1] + move[1]
            if 0 <= new_row < 3 and 0 <= new_col < 3:
                new_state = [row[:] for row in self.state]
                new_state[blank_pos[0]][blank_pos[1]] = new_state[new_row][new_col]
                new_state[new_row][new_col] = 0
                children.append(PuzzleNode(new_state, self, move))
        return children

    def is_goal(self):
        return self.state == [[0, 1, 2],
                              [3, 4, 5],
                              [6, 7, 8]]

    def heuristic(self):
        # Manhattan distance heuristic
        distance = 0
        for i in range(3):
            for j in range(3):
                if self.state[i][j] != 0:
                    row, col = divmod(self.state[i][j], 3)
                    distance += abs(row - i) + abs(col - j)
        return distance + self.depth


def a_star_search(initial_state):
    initial_node = PuzzleNode(initial_state)
    frontier = []
    heapq.heappush(frontier, initial_node)

    explored = set()

    while frontier:
        current_node = heapq.heappop(frontier)

        if current_node.is_goal():
            return current_node

        explored.add(current_node)

        for child in current_node.expand():
            if child not in explored:
                heapq.heappush(frontier, child)

    return None


def print_solution(solution_node):
    path = []
    current_node = solution_node
    while current_node:
        path.append(current_node)
        current_node = current_node.parent
    path.reverse()

    for i, node in enumerate(path):
        print("Step:", i, "Move:", node.move)
        print(node.state)


if __name__ == "__main__":
    initial_state = [[1, 2, 3], [0, 4, 6], [7, 5, 8]]
    solution_node = a_star_search(initial_state)
    if solution_node:
        print("Solution found!")
        print_solution(solution_node)
    else:
        print("No solution found!")
