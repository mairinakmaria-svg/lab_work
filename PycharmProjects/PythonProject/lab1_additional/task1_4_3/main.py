class Guest:
    def __init__(self, name, stay_period, budget):
        self.name = name
        self.stay_period = stay_period
        self.budget = budget

    def __str__(self):
        return f"{self.name}, {self.stay_period} days, Budget: {self.budget}"
class Room:
    def __init__(self, room_number, price_per_day, available_period):
        self.room_number = room_number
        self.price_per_day = price_per_day
        self.available_period = available_period  # Tuple (start_date, end_date)
        self.occupied = False  # Is the room occupied or not

    def is_available(self, check_period):
        return self.available_period[0] <= check_period[0] and self.available_period[1] >= check_period[1]
class Hotel:
    def __init__(self, rooms):
        self.rooms = rooms

    def find_available_room(self, check_period):
        for room in self.rooms:
            if room.is_available(check_period):
                return room
        return None