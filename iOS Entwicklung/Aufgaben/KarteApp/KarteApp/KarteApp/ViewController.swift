//
//  ViewController.swift
//  KarteApp
//
//

import UIKit
import CoreLocation
import MapKit
import UserNotifications

class ViewController: UIViewController, CLLocationManagerDelegate, MKMapViewDelegate, UIGestureRecognizerDelegate, UNUserNotificationCenterDelegate {
    
    @IBOutlet weak var home: UIButton!
    var isHome = true;
    var locationManager = CLLocationManager()
    var showUserLocation = true
    
    @IBOutlet var PinchGesture: UIPinchGestureRecognizer!
    @IBOutlet var SwipeGesture: UISwipeGestureRecognizer!
    @IBOutlet var LongPressGesture: UILongPressGestureRecognizer!
    
    @IBOutlet weak var MapSchow: MKMapView!
    var mapPoint1 = simpleMapPoint()
    var mapPoint2 = simpleMapPoint()
    var mapPoint3 = simpleMapPoint()
    var mapPoint4 = simpleMapPoint()
    var mapPoint5 = simpleMapPoint()
    var mapPoint6 = simpleMapPoint()
    /*
     GPS koordinaten fuer weg punkte
     52.505, 13.336
     52.505033,13.340516 Buchbinder
     52.504533,13.344146 nichts => Bus ist dann auf
     52.503338,13.350440 an der Urania => Bus ist dann auf
     52.505575,13.352295 herkulesbrucke => Bus ist dann auf
     52.506884,13.351888 nicht2 => Bus ist dann auf
     
     */
 

    override func viewDidLoad() {
        UNUserNotificationCenter.current().requestAuthorization(options: [.alert, .sound, .badge], completionHandler:  { didAllow, error in})
        
        home.tag = 1
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
        locationManager.requestAlwaysAuthorization()
        locationManager.startUpdatingLocation()
        
        MapSchow.showsUserLocation = true
        MapSchow.delegate = self
        
        PinchGesture.delegate = self
        SwipeGesture.delegate = self
        LongPressGesture.delegate = self

        
        let NotifyCenter = UNUserNotificationCenter.current()
        NotifyCenter.delegate = self
        
      //  UIPinchGestureRecognizer.delegete = self
        
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    
        self.mapPoint1.coordinate = CLLocationCoordinate2DMake(52.505, 13.336)
        self.mapPoint1.title = "Interesting View"
        self.mapPoint1.nameOfTheMapPoint = "poi1"
        self.mapPoint1.subtitle = "Pay attention to the harbour in the background"
        MapSchow.addAnnotation(mapPoint1)
        sendNotification(mapPoint1)

        self.mapPoint2.coordinate = CLLocationCoordinate2DMake(52.505033,13.340516)
        self.mapPoint2.title = "Buchbinder"
        self.mapPoint2.nameOfTheMapPoint = "poi2"
        self.mapPoint2.subtitle = "Place to get your books done"
        MapSchow.addAnnotation(mapPoint2)
        sendNotification(mapPoint2)
        
        self.mapPoint3.coordinate = CLLocationCoordinate2DMake(52.503338,13.350440)
        self.mapPoint3.title = "Some stupid buildings"
        self.mapPoint3.nameOfTheMapPoint = "poi3"
        self.mapPoint3.subtitle = "Office, or something. I don't know"
        MapSchow.addAnnotation(mapPoint3)
        sendNotification(mapPoint3)
        
        self.mapPoint4.coordinate = CLLocationCoordinate2DMake(52.503338,13.350440)
        self.mapPoint4.nameOfTheMapPoint = "poi4"
        self.mapPoint4.title = "An der Urania"
        self.mapPoint4.subtitle = "Next to the Urania theater"
        MapSchow.addAnnotation(mapPoint4)
        sendNotification(mapPoint4)
        
        
        self.mapPoint5.coordinate = CLLocationCoordinate2DMake(52.505575,13.352295)
        self.mapPoint5.nameOfTheMapPoint = "poi5"
        self.mapPoint5.title = "Hackelbruecke"
        self.mapPoint5.subtitle = "Some bridge over water. notihn special"
        MapSchow.addAnnotation(mapPoint5)
        sendNotification(mapPoint5)
        
        self.mapPoint6.coordinate = CLLocationCoordinate2DMake(52.506884,13.351888)
        self.mapPoint6.nameOfTheMapPoint = "poi6"
        self.mapPoint6.title = "CDU office"
        self.mapPoint6.subtitle = "And mexican embassy next to it"
        MapSchow.addAnnotation(mapPoint6)
   
        /*    let locattionnotification = UILocalNotification()
        locattionnotification.alertBody = "You have entered a high risk zone (Crown Range Road) , proceed with caution"
        locattionnotification.regionTriggersOnce = false
        locattionnotification.region = CLCircularRegion(center: mapPoint1.coordinate, radius: 1000, identifier: "MapPoint1")
        UIApplication.sharedApplication.scheduleLocalNotification(locattionnotification)
  */
    }
    
    func sendNotification(_ myMapPoint: simpleMapPoint){
        print("notification func called")
        let center = myMapPoint.coordinate
        let region = CLCircularRegion(center: center, radius: 100.0, identifier: "next to smth interesting")

        let content = UNMutableNotificationContent()
        content.title = myMapPoint.title ?? "title of the intersting thing"
        content.body = myMapPoint.subtitle ?? "look closely!"
        content.badge = 1
        region.notifyOnEntry = true
        region.notifyOnExit = false
        let trigger = UNLocationNotificationTrigger(region: region, repeats: false)
        
        let request = UNNotificationRequest(identifier: myMapPoint.nameOfTheMapPoint!, content: content, trigger: trigger)
        UNUserNotificationCenter.current().add(request, withCompletionHandler: nil)
    }
    

    func runAction(_ place: String) {
        sendNotification(mapPoint1)

        if (place == "Buchbinder"){
            print("Buchbinder")
        }
        print(place)
        //show local notification here
    }
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        let loc = locations.last
        let latVal = loc?.coordinate.latitude
        let lonVal = loc?.coordinate.longitude
        print("LAT:"+(latVal?.description)!)
        print("LON:"+(lonVal?.description)!)
        print()
        

    }
 
    @IBAction func homeButton(_ sender: UIButton) {
       let reg = MKCoordinateRegion(center: locationManager.location!.coordinate, latitudinalMeters: 1000, longitudinalMeters: 1000)
        MapSchow.setRegion(reg, animated: true)
       sender.isHidden = true
        isHome = true

    }
    
    func mapView(_ mapView: MKMapView, didUpdate userLocation:  MKUserLocation){
        if isHome == true{
            let currentLocation = userLocation.coordinate
            let reg = MKCoordinateRegion(center: currentLocation, latitudinalMeters: 1000, longitudinalMeters: 1000)
            MapSchow.setRegion(reg, animated: true)
        }
    }
    
    func userNotifiactionCenter(_ center: UNUserNotificationCenter, willPresent notification: UNNotification, withcomplitionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void){
        completionHandler([.alert, .sound])
    }
 
    
    func mapView(_ mapView: MKMapView!, viewFor annotation: MKAnnotation!)-> MKAnnotationView! {
        print("func annotation")
        
        if (!(annotation is simpleMapPoint) || ((annotation as! simpleMapPoint).nameOfTheMapPoint != "some_point")) {
            return nil
        }
        
        let reuseID = "first"
        var annotationView = mapView.dequeueReusableAnnotationView(withIdentifier: reuseID)
        if annotationView == nil {
            annotationView = MKPinAnnotationView(annotation: annotation, reuseIdentifier: reuseID)
            annotationView?.canShowCallout = false
        }
        else {
            annotationView?.annotation = annotation
        }
        return annotationView
    }

    
    func gestureRecognizer(_ gestureRecognizer: UIGestureRecognizer, shouldRecognizeSimultaneouslyWith otherGestureRecognizer: UIGestureRecognizer) -> Bool {
        switch gestureRecognizer{
        case PinchGesture:
            onPinch(PinchGesture)
        case SwipeGesture:
            onSwipe(SwipeGesture)
        case LongPressGesture:
            onLongPress(LongPressGesture)
        default:
            return false
        }
    return true
    }

    @IBAction func onLongPress(_ sender: Any) {
        print("longPress aufgerufen")
        isHome = false

        home.isHidden = false
        
    }

    @IBAction func onPinch(_ sender: UIPinchGestureRecognizer) {
        print("pinchaufgerufen")
        isHome = false

        home.isHidden = false
        
    }

    @IBAction func onSwipe(_ sender: UISwipeGestureRecognizer) {
        print("swipeaufgerufen")
        isHome = false
        
        home.isHidden = false

    }
    

}



