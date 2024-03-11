import hashlib
import secrets
import string

class SaltPepperHash:
    def __init__(self):
        self.users = {}

    def add_user(self, username, password):
        if username in self.users:
            raise ValueError("Username already exists.")
        
        salt = self.generate_salt()
        pepper = "9609Emmanuel2003"
        hashed_password = self.hash_password(password, salt, pepper)
        self.users[username] = {'salt': salt, 'pepper': pepper, 'hashed_password': hashed_password}

    def authenticate_user(self, username, password):
        if username in self.users:
            user_data = self.users[username]
            hashed_password = self.hash_password(password, user_data['salt'], user_data['pepper'])
            return hashed_password == user_data['hashed_password']
        else:
            return False

    def hash_password(self, password, salt, pepper):
        hashed_password = hashlib.md5(password.encode()).hexdigest()
        password_peppered = hashed_password + salt + pepper
        final_hashed_password = hashlib.md5(password_peppered.encode()).hexdigest()
        return final_hashed_password

    def display(self):
        print(self.users)
        
    def generate_salt(self):
        return ''.join(secrets.choice(string.ascii_letters + string.digits) for _ in range(8))    

password_manager = SaltPepperHash()
def create_user():
    username = input("Enter your username: ")
    password = input("Enter your password: ")
    password_manager.add_user(username, password)
    print("User created successfully.")

def display_dict():
    password_manager.display()

create_user()
create_user()
create_user() 

display_dict()

def authenticate_user():
    username = input("Enter your username: ")
    password = input("Enter your password: ")
    if password_manager.authenticate_user(username, password):
        print("Authentication successful.")
    else:
        print("Authentication failed.")
        

authenticate_user()
authenticate_user()