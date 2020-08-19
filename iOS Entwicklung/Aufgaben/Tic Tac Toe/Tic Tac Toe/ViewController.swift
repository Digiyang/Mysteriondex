//
//  ViewController.swift
//  Tic Tac Toe
//
//  Created by Moez Rjiba on 02.01.20.
//  Copyright © 2020 Moez Rjiba. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    var ActivePlayer = 1 //Cross
    var gameState = [0, 0, 0, 0, 0, 0, 0, 0, 0]
    
    let winningCombinations = [[0, 1, 2], [3, 4, 5], [6, 7, 8], [0, 3, 6], [1, 4, 7], [2, 5, 8], [0, 4, 8], [2, 4, 6]]
    var gameIsActive = true
    
    @IBOutlet weak var label: UILabel!
    @IBAction func action(_ sender: AnyObject)
    {
        if (gameState[sender.tag-1] == 0 && gameIsActive == true)
        {
            gameState[sender.tag-1] = ActivePlayer
            
            if (ActivePlayer == 1)
            {
                sender.setImage(UIImage(named: "Cross.png"), for: UIControl.State())
                ActivePlayer = 2
            }
            else
            {
                sender.setImage(UIImage(named: "Nought.png"), for: UIControl.State())
                ActivePlayer = 1
            }
        }
            for combination in winningCombinations
            {
                    if gameState[combination[0]] != 0 && gameState[combination[0]] == gameState[combination[1]] && gameState[combination[1]] == gameState[combination[2]]
                    {
                        gameIsActive = false
                        if gameState[combination[0]] == 1
                        {
                            //Cross has won
                            label.text = "CROSS HAS WON!"
                        }
                        else
                        {
                            //Nought has won
                            label.text = "NOUGHT HAS WON!"
                        }
                        
                        PlayAgainButton.isHidden = false
                        label.isHidden = false
                    }
            }
        gameIsActive = false
        for i in gameState
        {
           if i == 0
           {
                gameIsActive = true
                break
            }
        }
        if gameIsActive == false
        {
            label.text = "IT WAS A DRAW!"
            label.isHidden = false
            PlayAgainButton.isHidden = false
        }
    }
    
    
    @IBOutlet weak var PlayAgainButton: UIButton!
    @IBAction func PlayAgain(_ sender: Any)
    {
        gameState = [0, 0, 0, 0, 0, 0, 0, 0, 0]
        gameIsActive = true
        ActivePlayer = 1
        
        PlayAgainButton.isHidden = true
        label.isHidden = true
        
        for i in 1...9
        {
            let button = view.viewWithTag(i) as! UIButton
            button.setImage(nil, for: UIControl.State())
        }
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated 
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }
}

