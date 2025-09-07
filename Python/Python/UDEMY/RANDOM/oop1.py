class User:
    def __init__(self,user_id,username):
        self.id=user_id
        self.username=username
        self.followers=0
        self.following=0
    def follow(self,user):
        self.following+=1
        user.followers+=1
user1=User(1,"Uday")
user2=User(2,"Pari")
print(user1.followers)
print(user2.followers)
user1.follow(user2)
user2.follow(user1)
print(user1.followers)
print(user2.followers)