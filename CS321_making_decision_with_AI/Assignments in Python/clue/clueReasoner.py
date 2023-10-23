'''ClueReasoner.py - project skeleton for a propositional reasoner
for the game of Clue.  Unimplemented portions have the comment "TO
BE IMPLEMENTED AS AN EXERCISE".  The reasoner does not include
knowledge of how many cards each player holds.
Originally by Todd Neller
Ported to Python by Dave Musicant

Copyright (C) 2019 Dave Musicant

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Information about the GNU General Public License is available online at:
  http://www.gnu.org/licenses/
To receive a copy of the GNU General Public License, write to the Free
Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.'''

import SATSolver

# Initialize important variables
caseFile = "cf"
players = ["sc", "mu", "wh", "gr", "pe", "pl"]
extendedPlayers = players + [caseFile]
suspects = ["mu", "pl", "gr", "pe", "sc", "wh"]
weapons = ["kn", "ca", "re", "ro", "pi", "wr"]
rooms = ["ha", "lo", "di", "ki", "ba", "co", "bi", "li", "st"]
cards = suspects + weapons + rooms

def getPairNumFromNames(player,card):
    return getPairNumFromPositions(extendedPlayers.index(player),
                                   cards.index(card))

def getPairNumFromPositions(player,card):
    return player*len(cards) + card + 1

# TO BE IMPLEMENTED AS AN EXERCISE
def initialClauses():
    clauses = []

    # Each card is in at least one place (including case file).
    for c in cards:
        clauses.append([getPairNumFromNames(p,c) for p in extendedPlayers])

    # A card cannot be in two places.
    for c in cards:
        for pc in extendedPlayers:
            for pnoc in extendedPlayers:
                if pc != pnoc:
                    clauses.append([-getPairNumFromNames(pc, c), -getPairNumFromNames(pnoc, c)])


    # At least one card of each category is in the case file.
    cfsuspect = []
    for s in suspects:
        cfsuspect.append(getPairNumFromNames(caseFile, s))
    clauses.append(cfsuspect)
    cfweapon = []
    for w in weapons:
        cfweapon.append(getPairNumFromNames(caseFile, w))
    clauses.append(cfweapon)
    cfroom = []
    for r in rooms:
        cfroom.append(getPairNumFromNames(caseFile, r))
    clauses.append(cfroom)

    # No two cards in each category can both be in the case file.
    for w1 in weapons:
        for w2 in weapons:
            if w1 != w2:
                clauses.append([-getPairNumFromNames(caseFile, w1), -getPairNumFromNames(caseFile,w2)])

    
    for r1 in rooms:
        for r2 in rooms:
            if r1 != r2:
                clauses.append([-getPairNumFromNames(caseFile,r1), -getPairNumFromNames(caseFile,r2)])

    for s1 in suspects:
        for s2 in suspects:
            if s1 != s2:
                clauses.append([-getPairNumFromNames(caseFile,s1), -getPairNumFromNames(caseFile, s2)])

    #test for one card can't be in two places
    # clauses.append([getPairNumFromNames("wh","kn")])
    # print(query("sc","kn",clauses))

    #test for at least one card for each category
    # clauses.append([-getPairNumFromNames(caseFile, "kn")])
    # clauses.append([-getPairNumFromNames(caseFile, "ca")])
    # clauses.append([-getPairNumFromNames(caseFile, "re")])
    # clauses.append([-getPairNumFromNames(caseFile, "ro")])
    # clauses.append([-getPairNumFromNames(caseFile, "pi")])
    # print(query(caseFile,"wr",clauses))

    # test for No two cards in each category can both be in the case file.
    # clauses.append([getPairNumFromNames(caseFile, "pi")])
    # print(query(caseFile,"wr",clauses))
    # clauses.append([getPairNumFromNames(caseFile, "ha")])
    # print(query(caseFile,"lo",clauses))
    # clauses.append([getPairNumFromNames(caseFile, "mu")])
    # print(query(caseFile,"gr",clauses))

    return clauses

# TO BE IMPLEMENTED AS AN EXERCISE  
def hand(player,cards):
    clauses = []
    for c in cards:
        clauses.append([getPairNumFromNames(player, c)])
    return clauses


# TO BE IMPLEMENTED AS AN EXERCISE  
def suggest(suggester,card1,card2,card3,refuter,cardShown):
    clauses = []
    if refuter == None:
        for p in players:
            if p != suggester:
                clauses.append([-getPairNumFromNames(p, card1)])
                clauses.append([-getPairNumFromNames(p, card2)])
                clauses.append([-getPairNumFromNames(p, card3)])
    else:
        if cardShown != None:
            clauses.append([getPairNumFromNames(refuter,cardShown)])
        else:
            clauses.append([getPairNumFromNames(refuter, card1), getPairNumFromNames(refuter, card2), getPairNumFromNames(refuter, card3)])

        cnt = players.index(suggester) + 1
        while players[cnt % len(players)] != refuter:
            p = players[cnt % len(players)]
            clauses.append([-getPairNumFromNames(p,card1)])
            clauses.append([-getPairNumFromNames(p,card2)])
            clauses.append([-getPairNumFromNames(p,card3)])
            cnt += 1

    return clauses

# TO BE IMPLEMENTED AS AN EXERCISE  
def accuse(accuser,card1,card2,card3,isCorrect):
    clauses = []
    if isCorrect:
        clauses.append([getPairNumFromNames(caseFile, card1)])
        clauses.append([getPairNumFromNames(caseFile, card2)])
        clauses.append([getPairNumFromNames(caseFile, card3)])
    else:
        clauses.append([-getPairNumFromNames(caseFile, card1), -getPairNumFromNames(caseFile, card2), -getPairNumFromNames(caseFile, card3)])

    clauses.append([-getPairNumFromNames(accuser,card1)])
    clauses.append([-getPairNumFromNames(accuser,card2)])
    clauses.append([-getPairNumFromNames(accuser,card3)])
    return clauses

def query(player,card,clauses):
    return SATSolver.testLiteral(getPairNumFromNames(player,card),clauses)

def queryString(returnCode):
    if returnCode == True:
        return 'Y'
    elif returnCode == False:
        return 'N'
    else:
        return '-'

def printNotepad(clauses):
    for player in players:
        print('\t', player, end=' ')
    print('\t', caseFile)
    for card in cards:
        print(card,'\t', end=' ')
        for player in players:
            print(queryString(query(player,card,clauses)),'\t', end=' ')
        print(queryString(query(caseFile,card,clauses)))

def playClue():
    clauses = initialClauses()
    clauses.extend(hand("sc",["wh", "li", "st"]))
    clauses.extend(suggest("sc", "sc", "ro", "lo", "mu", "sc"))
    clauses.extend(suggest("mu", "pe", "pi", "di", "pe", None))
    clauses.extend(suggest("wh", "mu", "re", "ba", "pe", None))
    clauses.extend(suggest("gr", "wh", "kn", "ba", "pl", None))
    clauses.extend(suggest("pe", "gr", "ca", "di", "wh", None))
    clauses.extend(suggest("pl", "wh", "wr", "st", "sc", "wh"))
    clauses.extend(suggest("sc", "pl", "ro", "co", "mu", "pl"))
    clauses.extend(suggest("mu", "pe", "ro", "ba", "wh", None))
    clauses.extend(suggest("wh", "mu", "ca", "st", "gr", None))
    clauses.extend(suggest("gr", "pe", "kn", "di", "pe", None))
    clauses.extend(suggest("pe", "mu", "pi", "di", "pl", None))
    clauses.extend(suggest("pl", "gr", "kn", "co", "wh", None))
    clauses.extend(suggest("sc", "pe", "kn", "lo", "mu", "lo"))
    clauses.extend(suggest("mu", "pe", "kn", "di", "wh", None))
    clauses.extend(suggest("wh", "pe", "wr", "ha", "gr", None))
    clauses.extend(suggest("gr", "wh", "pi", "co", "pl", None))
    clauses.extend(suggest("pe", "sc", "pi", "ha", "mu", None))
    clauses.extend(suggest("pl", "pe", "pi", "ba", None, None))
    clauses.extend(suggest("sc", "wh", "pi", "ha", "pe", "ha"))
    clauses.extend(suggest("wh", "pe", "pi", "ha", "pe", None))
    clauses.extend(suggest("pe", "pe", "pi", "ha", None, None))
    clauses.extend(suggest("sc", "gr", "pi", "st", "wh", "gr"))
    clauses.extend(suggest("mu", "pe", "pi", "ba", "pl", None))
    clauses.extend(suggest("wh", "pe", "pi", "st", "sc", "st"))
    clauses.extend(suggest("gr", "wh", "pi", "st", "sc", "wh"))
    clauses.extend(suggest("pe", "wh", "pi", "st", "sc", "wh"))
    clauses.extend(suggest("pl", "pe", "pi", "ki", "gr", None))
    print('Before accusation: should show a single solution.')
    printNotepad(clauses)
    print()
    clauses.extend(accuse("sc", "pe", "pi", "bi", True))
    print('After accusation: if consistent, output should remain unchanged.')
    printNotepad(clauses)

if __name__ == '__main__':
    playClue()
    # clauses = initialClauses()
    # test for hand()
    # clauses.extend(hand("sc",["kn", "pi"]))
    # print(query("wh","kn",clauses))

    # test for suggest with no refuter
    # clauses.append([-getPairNumFromNames("sc","wh")])
    # clauses.append([-getPairNumFromNames("sc","lo")])
    # clauses.append([-getPairNumFromNames("sc","kn")])
    # clauses.extend(suggest("sc","wh","kn","lo",None, None))
    # printNotepad(clauses)

    # test for suggestion with refuter with card shown
    # cla = suggest("pe","wh","kn","lo","mu", "lo")
    # clauses.extend(suggest("pe","wh","kn","lo","mu", "lo"))
    # printNotepad(clauses)
    # print(cla)

    # test for suggestion with refuter with no card shown
    # cla = suggest("pe","wh","kn","lo","mu", None)
    # clauses.extend(suggest("pe","wh","kn","lo","mu", None))
    # printNotepad(clauses)
    # print(cla)


    #test for correct accusation
    # cla = accuse("sc","wh","kn","st",True)
    # clauses.extend(cla)
    # printNotepad(clauses)
    # print(cla)

    #test for wrong accusation
    # cla = accuse("sc","wh","kn","st",False)
    # clauses.extend(cla)
    # clauses.extend([[147]])
    # clauses.extend([[133]])
    # printNotepad(clauses)
    # print(clauses)


    