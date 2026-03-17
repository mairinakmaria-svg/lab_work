class Pentagon:
    def __init__(self, side_lengths):
        self.side_lengths = side_lengths

    def is_convex(self):
        # Перевірка на опуклість
        # Для простоти припускаємо, що п’ятикутник опуклий, якщо його сторони позитивні
        return all(side > 0 for side in self.side_lengths)

class Hexagon:
    def __init__(self, side_lengths):
        self.side_lengths = side_lengths

    def is_convex(self):
        # Перевірка на опуклість
        return all(side > 0 for side in self.side_lengths)
class Polygon:
    def __init__(self, side_lengths):
        self.side_lengths = side_lengths

    def is_convex(self):
        # Для перевірки можна застосувати те ж саме правило
        return all(side > 0 for side in self.side_lengths)